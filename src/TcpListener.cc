#include "TcpListener.h"

#include <sys/socket.h>
#include <error.h>


TcpListener::TcpListener(): m_Sock(0), m_connected(false) {}

TcpListener::~TcpListener() {
    if (m_bConnected) {
        shutdown(m_Sock);
    }
    if ( m_Sock > 0) {
        close(m_Sock);
    }
}

bool TcpListener::bind(const IpAddr &addr) {
    switdh(addr.get_addr_type()) {
        case v4:
            m_Sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
            break;
        case v6:
            m_Sock = socket(PF_INET6, SOCK_STREAM, IPPROTO_TCP);
            break;
        default: return false;
    }
    if ( bind(m_Sock, addr.get_sa_ptr(), addr.get_size()) != 0 ) {
        // TODO: check error no and print out the error message
        return false;
    }
    return true;
}

TcpStream TcpListener::accept() {
    
}


bool TcpListener::is_connected() {
    return m_bConnected;
}

IpAddr TcpListener::local_addr() {

}
