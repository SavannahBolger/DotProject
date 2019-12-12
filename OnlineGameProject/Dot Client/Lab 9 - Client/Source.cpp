/*
Tutorial 13 Client Solution
Author: Pindrought
Date: 02/26/2017
*/

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "Client.h"
#include <iostream>

int main()
{
	Client myClient("192.168.178.29",1111); //Create client to connect to server 127.0.0.1 [localhost] on port 1111
	if (!myClient.Connect()) //If client fails to connect...
	{
		std::cout << "Failed to connect to server..." << std::endl;
		system("pause");
		return -1;
	}
	std::string userinput; //holds the user's chat message
	while (true)
	{
		std::getline(std::cin,userinput); //Get line if user presses enter and fill the buffer
		myClient.SendString(userinput); //Send string to server
	}

	std::cin.get();
	return 0;
}

