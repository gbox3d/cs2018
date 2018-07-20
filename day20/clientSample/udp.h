#pragma once

#define BUFLEN 1024
struct S_UDPObject {

	SOCKET m_socket;
	sockaddr_in m_serverAddr, m_si_otherAddr;
	int m_recv_len, m_slen;
	char m_buf[BUFLEN];
	WSADATA m_wsa;
};

extern S_UDPObject g_udpObject;

int openNetWork(int nPort);
void closeNetwork();
void sendUdp_Pos(irr::core::vector2df pos);

#define MAX_GHOST 32
struct S_GHOST
{
	char m_szName[64];
	irr::core::vector2df m_vPos;
};
