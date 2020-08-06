#ifndef TCP_LISTENER_H
#define TCP_LISTENER_H

#include "IpAddr.h"
#include "TcpStream.h"

using sock_t = int;

class TcpListener {
    public:
        TcpListener();
        ~TcpListener();
        TcpListener(const TcpListener&) = delete;
        TcpListener& operator=(const TcpListener&) = delete;

    public:
        bool bind(const IpAddr&);
        TcpStream accept();
        bool is_connected() const;
        IpAddr local_addr() const;

    private:
        sock_t  m_Sock;
        bool    m_bConnected;
};



#endif