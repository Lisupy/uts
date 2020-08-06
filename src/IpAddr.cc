#include "IpAddr.h"
#include "arpa/inet.h"

#include <string> 
#include <cstring>

using std::string;

IpAddr::IpAddr() {
    std::memset(&m_addr, 0, sizeof(m_addr));
}


IpAddr::IpAddr(IpAddrType ip_type, const string &str_ip, uint16_t port) :IpAddr() {
    std::memset(&m_addr, 0, sizeof(m_addr));
    switch (ip_type) {
        case v4:
            sockaddr_in *p_m_addr = (sockaddr_in *)&m_addr;
            p_m_addr->sin_family = AF_INET;
            p_m_addr->sin_port = htons(port);
            inet_pton(AF_INET, str_ip.c_str(), &(p_m_addr->sin_addr));
            break;
        case v6:
            sockaddr_in6 *p_m_addr = (sockaddr_in6 *)&m_addr;
            p_m_addr->sin6_family = AF_INET6;
            p_m_addr->sin6_port = htons(port);
            inet_pton(AF_INET6, str_ip.c_str(), &(p_m_addr->sin6_addr));
            break;
        default:
            break;
    }
}

// ================ public interface ==================
string IpAddr::get_str() const {
    string str_ip = get_host_str();
    uint16_t port = get_port();
    str_ip += ":" + std::to_string(port);
}

string IpAddr::get_host_str() const {
    char buff[INET6_ADDRSTRLEN];
    const char *ptr_str = nullptr;
    switch (get_addr_type()) {
        case v4:
            ptr_str = inet_ntop(m_addr.ss_family, &(((sockaddr_in *)&m_addr)->sin_addr), buff, sizeof(buff));
            break;
        case v6:
            ptr_str = inet_ntop(m_addr.ss_family, &(((sockaddr_in6 *)&m_addr)->sin6_addr), buff, sizeof(buff));
            break;
        default:
            break;
    }
    if (ptr_str == nullptr) {
        return "";
    }
    return ptr_str;
}

uint16_t IpAddr::get_port() const {
    uint16_t port = 0;
    switch(get_addr_type()) {
        case v4:
            port = ((sockaddr_in *)&m_addr)->sin_port;
            break;
        case v6:
            port = ((sockaddr_in6 *)&m_addr)->sin6_port;
            break;
        default:
            break;
    }
    return ntohs(port);
}

IpAddrType IpAddr::get_addr_type() const {
    switch (m_addr.ss_family) {
        case AF_INET: return v4;
        case AF_INET6: return v6;
        default: return unknown;
    }
}

int IpAddr::get_size() const {
    switch(get_addr_type()) {
        case v4: return sizeof(sockaddr_in);
        case v6: return sizeof(sockaddr_in6);
        default: return sizeof(m_addr);
    }
}

sockaddr* IpAddr::get_sa_ptr() {
    return (sockaddr*) &m_addr;
}

const sockaddr* get_sa_ptr() const {
    return (sockaddr*) &m_addr;
}
