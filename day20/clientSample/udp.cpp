#include "stdafx.h"
//----------------------------------------------------------


#include "udp.h"


S_UDPObject g_udpObject;


S_GHOST g_ghosts[MAX_GHOST];


DWORD ThreadID;
HANDLE hThread;
DWORD WINAPI ThreadFunc(LPVOID temp)
{
	//S_UDPObject *pUdp = (S_UDPObject *)&temp;
	S_UDPObject *pUdp = &g_udpObject;

	OutputDebugString(L"Start recv Thread \n");
	//int slen;
	while (1)
	{
		//clear the buffer by filling null, it might have previously received data
		memset(pUdp->m_buf, '\0', BUFLEN);
		OutputDebugString(L"Waiting for data...\n");
		//try to receive some data, this is a blocking call
		if ((pUdp->m_recv_len = recvfrom(pUdp->m_socket, pUdp->m_buf, BUFLEN, 0,
			(sockaddr *)&pUdp->m_si_otherAddr, &pUdp->m_slen))
			== SOCKET_ERROR)
		{
			OutputDebugString(L"recvfrom() failed with error.\n");
		}
		else {
			pUdp->m_buf[pUdp->m_recv_len] = 0x00;
			OutputDebugString(L"recv Data \n");
			OutputDebugStringA(pUdp->m_buf);
			OutputDebugString(L"\n");

			cJSON * root = cJSON_Parse(pUdp->m_buf);

			int _num = cJSON_GetArraySize(root);
			int i = 0;
			for ( i = 0; i < _num; i++) {

				cJSON *item= cJSON_GetArrayItem(root, i);
				g_ghosts[i].m_vPos.X =  cJSON_GetObjectItemCaseSensitive(item, "x")->valuedouble;
				g_ghosts[i].m_vPos.Y = cJSON_GetObjectItemCaseSensitive(item, "y")->valuedouble;
				strcpy_s(g_ghosts[i].m_szName, sizeof(g_ghosts[i].m_szName), "noname");
			}
			strcpy_s(g_ghosts[i].m_szName, sizeof(g_ghosts[i].m_szName), "");

		}

	}
	return 0;
}


int _openNetWork(S_UDPObject *pUdp, int nPort)
{
	pUdp->m_slen = sizeof(pUdp->m_si_otherAddr);

	if (WSAStartup(MAKEWORD(2, 2), &pUdp->m_wsa) != 0)
	{
		//return
		//printf("Failed. Error Code : %d", WSAGetLastError());
		//exit(EXIT_FAILURE);
		OutputDebugString(L"WSAStartup Failed.\n");
		return WSAGetLastError();
	}
	OutputDebugString(L"Initialised.\n");

	//Create a socket
	if ((pUdp->m_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		//printf("Could not create socket : %d", WSAGetLastError());
		OutputDebugString(L"Could not create socket\n");
		return WSAGetLastError();
	}
	OutputDebugString(L"Socket created..\n");

	//Prepare the sockaddr_in structure
	pUdp->m_serverAddr.sin_family = AF_INET;
	pUdp->m_serverAddr.sin_addr.s_addr = INADDR_ANY;
	pUdp->m_serverAddr.sin_port = htons(nPort);

	//Bind
	if (bind(pUdp->m_socket, (sockaddr *)&pUdp->m_serverAddr, sizeof(pUdp->m_serverAddr)) == SOCKET_ERROR)
	{
		OutputDebugString(L"Bind failed with error code.\n");
		return  WSAGetLastError();
	}
	{
		WCHAR szBuf[256];
		swprintf_s(szBuf, L"bind port %d \n", nPort);
		OutputDebugString(szBuf);
	}
	

	hThread = CreateThread(NULL, 0, ThreadFunc, &g_udpObject, 0, &ThreadID);

	return 0;

}


int openNetWork(int nPort)
{
	return _openNetWork(&g_udpObject,nPort);
}

void _closeNetwork(S_UDPObject *pUdp)
{
	closesocket(pUdp->m_socket);
	WSACleanup();
}

void closeNetwork()
{
	_closeNetwork(&g_udpObject);

}

void sendUdp_Pos(irr::core::vector2df pos)
{

	cJSON *root = NULL;
	root = cJSON_CreateObject();
	cJSON_AddNumberToObject(root, "x", irr::core::round32(pos.X));
	cJSON_AddNumberToObject(root, "y", irr::core::round32(pos.Y));
	char szBuf[512];
	cJSON_PrintPreallocated(root, szBuf, 512, 0);

	//OutputDebugStringA(szBuf);
	//OutputDebugStringA("\n");

	sockaddr_in si_other;
	int slen = sizeof(si_other);
	memset((char *)&si_other, 0, slen);
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(3333);
	//si_other.sin_addr.S_un.S_addr = inet_addr("14.55.107.250");
	si_other.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (sendto(g_udpObject.m_socket, szBuf, strlen(szBuf), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
	{
		DWORD code = GetLastError();
		OutputDebugStringA("sendto() failed with error code ");
	}


}
