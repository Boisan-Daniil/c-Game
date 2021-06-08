// Server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#pragma warning(disable: 4996)

SOCKET Connections[100];
int Counter = 0;

void ClientHandler(int index) {
	int msg_size; 
	while (true) {
		recv(Connections[index], (char*)&msg_size, sizeof(int), NULL); // Принимаем сообщения от клиентов
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';
		recv(Connections[index], msg, msg_size, NULL); // Проверка для того что бы игрок который отправил сообщение, не получил его обратно
		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}

			send(Connections[i], (char*)&msg_size, sizeof(int), NULL); // Отправляяем сообщения всем остальным клиентам
			send(Connections[i], msg, msg_size, NULL);
		}
		delete[] msg;
	}
}


int main()
{
	//WSAStartup - загрузка сетевой библиотеки
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	// Сокет с IP , портом и семейством протоколов
	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	// Прослушка порта через сокет
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	// Объявление новго сокета для соеденения с клииентом
	SOCKET newConnection;
	for (int i = 0; i < 100; i++) { // максимально клиентов - 100
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		if (newConnection == 0) {
			std::cout << "Error #2\n";
		}
		else {
			std::cout << "Client "  << i <<" Connected!\n"; // При соеденении с клиентом, выводим в консоль сервера инфу
			
			std::string msg = "You are player ";
			std::string playerID = std::to_string(i); // Даем id каждому клиенту
			msg.append(playerID);
			int msg_size = msg.size();
			
			send(newConnection, (char*)&msg_size, sizeof(int), NULL); // Отправка сообщения клиенту который законектился
			send(newConnection, msg.c_str(), msg_size, NULL);

			Connections[i] = newConnection;
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL); // Создание потоко для чата
		}
	}


	system("pause");
	return 0;
}

