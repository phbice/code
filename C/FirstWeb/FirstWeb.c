/*
Web Serverr
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include "constant.h"

#pragma comment(lib,"ws2_32")

SOCKET ForConnect(int iPort);
//int RecvRequest(SOCKET sClient, char * MessageBuffer);
int Respond(SOCKET sClient, char * MessageBuffer);

int main(void)
{
	ForConnect(80);
	return 0;
}

SOCKET ForConnect(int iPort)
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;

	SOCKET sListen;
	SOCKET sClient;
	struct sockaddr_in sin;
	struct sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);

	char * MessageBuffer = (char *)malloc(4096);

	//绑定IP和端口
	sin.sin_family = AF_INET;
	sin.sin_port = htons(iPort);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;

	//初始化WSA
	if (WSAStartup(sockVersion, &wsaData) != 0)
		return 0;

	//创建套接字
	sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sListen == INVALID_SOCKET)
	{
		fprintf(stderr, "Socket error !\n");
		return sListen;
	}

	if (bind(sListen, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		fprintf(stderr, "Bind error !");
		return sListen;
	}

	//开始监听
	if (listen(sListen, 5) == SOCKET_ERROR)
	{
		fprintf(stderr, "Listen error !");
		return sListen;
	}

	//接受连接
	while (1)
	{
		//printf("Waiting for connection...\n");
		sClient = accept(sListen, (SOCKADDR *)&remoteAddr, &nAddrlen);
		if (sClient == INVALID_SOCKET)
		{
			fprintf(stderr, "Accept error !\n");
			continue;
		}
		recv(sClient, MessageBuffer, 4096, 0);
		Respond(sClient, MessageBuffer);
		//inet_ntop(sin.sin_family, &(remoteAddr.sin_addr), szClientIP, iBufferSize);
	}
	closesocket(sListen);
	WSACleanup();
	free(MessageBuffer);
	return sClient;
}

int Respond(SOCKET sClient, char * MessageBuffer)
{
	static char respond_header[256] = "HTTP/1.1 200 OK\r\n\
Connection: close\r\n\
Content-Length: 200\r\n\
Content-Type: text/html\r\n\r\n";
	int i;
	char url[256];

	int fread_size;
	char * htm_temp = malloc(4096);
	FILE * htm;
	memset(htm_temp, 0, 4096);
	if (strncmp(MessageBuffer, "GET ", 4) == 0)
	{
		for (i = 0; MessageBuffer[i + 4] != ' '; i++)
		{
			url[i] = MessageBuffer[i + 4];
		}
		url[i] = 0;
	}
	if (strcmp(url, "/") == 0)
	{
		htm = fopen("F:\\site\\index.htm", "rb");
		send(sClient, respond_header, (int)strlen(respond_header), 0);
		while (!feof(htm))
		{
			fread_size = (int)fread(htm_temp, 1, 4096, htm);
			send(sClient, htm_temp, fread_size, 0);
		}
	}
	free(htm_temp);
	return 0;
}

//int RecvFile(FILE * pRecvFile, SOCKET sClient)
//{
//	static int iRecvBufferSize;
//	static int optlen = sizeof(int);
//	int iRecvSize;
//	char * pRecvBuffer;
//
//	getsockopt(sClient, SOL_SOCKET, SO_RCVBUF, (char *)&iRecvBufferSize, &optlen);
//	pRecvBuffer = (char *)malloc(iRecvBufferSize);
//
//	while ((iRecvSize = recv(sClient, pRecvBuffer, iRecvBufferSize, 0)) > 0)
//		fwrite(pRecvBuffer, 1, iRecvSize, pRecvFile);
//
//	free(pRecvBuffer);
//	pRecvBuffer = NULL;
//	return 0;
//}