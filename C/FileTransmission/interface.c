#include <stdio.h>
#include <stdlib.h>
#include <WS2tcpip.h>
#include "constant.h"

SOCKET ConnectTo(char * szServerIP, int iPort);
int SendFile(FILE * pSendFile, SOCKET sClient);

SOCKET ForConnect(int iPort, char * szClientIP, int iBufferSize);
int RecvFile(FILE * pRecvFile, SOCKET sClient);

int FT_send();
int FT_receive();

int main(int argc, char* argv[])
{
	int choice;
	printf("( 1 ) Send file.\n");
	printf("( 2 ) Receive file.\n");
	printf("Please input your choice[1/2] >");
	choice = getchar();
	if (getchar() != '\n')
	{
		while (getchar() != '\n')
			;
		printf("Please input only one number, '1' or '2'.\n");
	}
	switch (choice)
	{
	case '1':
		FT_send();
		break;
	case '2':
		FT_receive();
		break;
	default:
		printf("Please enter '1' or '2'.\n");
	}

	return 0;
}

int FT_send()
{
	static char szServerIP[MAX_IPV4ADDR_LEN];
	static char szFileName[MAX_FILENAME_LEN];

	FILE * pSendFile;
	SOCKET sClient;

		//Input file name
	while (1)
	{
		printf("Input file name >");
		gets_s(szFileName, MAX_FILENAME_LEN);
		if (fopen_s(&pSendFile, szFileName, "rb"))
			fprintf(stderr, "Can't open file: %s", szFileName);
		break;
	}

		//Connect to a reciver
	while (1)
	{
		printf("Input the Reciver's IP address >");
		gets_s(szServerIP, MAX_IPV4ADDR_LEN);
		sClient = ConnectTo(szServerIP, PORT);
		if (sClient == INVALID_SOCKET || sClient == SOCKET_ERROR)
			fprintf(stderr, "Can't connect to the receiver, please try again\n");
		else
			break;
	}

	SendFile(pSendFile, sClient);

	fclose(pSendFile);
	closesocket(sClient);
	WSACleanup();

	return 0;
}

int FT_receive()
{
	static char szClientIP[MAX_IPV4ADDR_LEN];
	static char szFileName[MAX_FILENAME_LEN];

	SOCKET sClient;
	FILE * pRecvFile;

	while (1)
	{
		printf("Enter file name (any existing file will be overridden!)\n>");
		gets_s(szFileName, MAX_FILENAME_LEN);
		if (fopen_s(&pRecvFile, szFileName, "wb"))
			fprintf(stderr, "Can't create file, please try again.\n");
		else
			break;
	}
	
	sClient = ForConnect(PORT, szClientIP, MAX_IPV4ADDR_LEN);

	printf("Accept a connetion: %s \n", szClientIP);

	RecvFile(pRecvFile, sClient);

	fclose(pRecvFile);

	closesocket(sClient);
	WSACleanup();

	return 0;
}
