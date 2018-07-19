#include "stdafx.h"

void exam5_udp2()
{
	const int BUF_SIZE = 1024;
	const int PORT = 13333;

	SOCKET s;
	sockaddr_in peer_this, peer_other;

	char szBuf[BUF_SIZE];
	WSADATA wsa;

	puts("\n Init socket.... \n");

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf_s("failed WSAStartup %d \n", WSAGetLastError());
	}
	puts("Init socket....success \n");

	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
		printf_s("failed create socket %d \n", WSAGetLastError());
	}
	puts("create socket....success \n");

	peer_this.sin_family = AF_INET;
	peer_this.sin_addr.S_un.S_addr = INADDR_ANY;
	peer_this.sin_port = htons(PORT);

	if (bind(s, (sockaddr *)&peer_this, sizeof(peer_this)) == SOCKET_ERROR) {
		printf_s("bind error %d", WSAGetLastError());
	}
	printf_s("bind success  14.55.207.250 %d \n",PORT );

	srand(  time(NULL) );
	int _rnd = rand() % 100;
	//printf("%d \n", _rnd);
	

	int recv_len, slen;
	while (1) {
		puts("wait data....\n");
		fflush(stdout);
		memset(szBuf, 0x00, BUF_SIZE);
		slen = sizeof(peer_other);
		if ((recv_len = recvfrom(s, szBuf, BUF_SIZE, 0, (sockaddr *)&peer_other, &slen)) == SOCKET_ERROR) {
			printf_s("recvform failed %d\n", WSAGetLastError());
		}

		printf_s("remote info : %s , %d \n", inet_ntoa(peer_other.sin_addr), ntohs(peer_other.sin_port));
		printf_s("Data %s\n", szBuf);
		//{"num":12}
		cJSON *pRoot = cJSON_Parse(szBuf);

		if (!pRoot) {
			puts("parse error \n");
		}
		else {
			cJSON *pNum = cJSON_GetObjectItemCaseSensitive(pRoot, "num");
			if (pNum) {
				printf("your number is %d \n", pNum->valueint);
				char _szBuf[1024];
				if (pNum->valueint > _rnd) {
					//puts("TOO BIG\n");
					strcpy_s(_szBuf, "too big");
					
				}
				else if (pNum->valueint < _rnd) {
					//puts("too samll\n");
					strcpy_s(_szBuf, "too small");
				}
				else {
					//puts("great!! u a winner");
					strcpy_s(_szBuf, "Great!! U A Winnerl");
				}
				puts(_szBuf);
				puts("\n");
				sendto(s, _szBuf, strlen(_szBuf), 0, (sockaddr *)&peer_other, ntohs(peer_other.sin_port));
			}
			else {
				puts("똑바로 보내세요! \n");
			}
			

		}


	}

}
