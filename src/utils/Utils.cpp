#include "Utils.h"
#include "SysInfo.h"
#include <iostream>

Utils::Utils()
{
}

Utils::~Utils()
{
}

void Utils::printMessage(string text)
{
    cout << "* " << SysInfo::getSystemName() << " message: " << text << endl;
}

void Utils::printFramedMessage(string text, string symbol, int length)
{
    cout << replicate(symbol, length) << endl;
    cout << text << endl;
    cout << replicate(symbol, length) << endl;
}

string Utils::replicate(string text, int times)
{
    string buffer;
    for (int count = 0; count < times; count++)
    {
        buffer += text;
    }
    return (buffer);
}

 void Utils::clearScreen()
	{
	system("clear||cls");
	}