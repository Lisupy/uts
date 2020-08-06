#ifndef TCP_STREAM_H
#define TCP_STREAM_H

using sock_t = int;

class TcpStream {
    public:
        TcpStream(sock_t sock);
        ~TcpStream();

    public:
        IpAddr get_peer_addr() const;


    private:
        m_sock;
};

#endif