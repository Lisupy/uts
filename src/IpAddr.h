#ifndef IpAddr_H
#define IpAddr_H

#include <string> 
#include <netinet/in.h> 
#include <sys/socket.h> 


enum IpAddrType {
    unknown = 0,
    v4,
    v6,
};


// 对IP地址的封装，IPv4 & IPv6
class IpAddr {
    public:
        IpAddr();
        ~IpAddr() = default;
        IpAddr(const IpAddr &) = default;
        IpAddr& operator=(const IpAddr&) = default;
        IpAddr(IpAddrType type, const std::string &, uint16_t port);

    public:
        std::string get_str() const;
        std::string get_host_str() const;
        uint16_t get_port() const;
        IpAddrType get_addr_type() const;
        
        int get_size() const;
        sockaddr* get_sa_ptr();
        const sockaddr* get_sa_ptr() const;

    private:
        sockaddr_storage m_addr;
};

#endif
