#include "Utils.h"
#include "SysInfo.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

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

void Utils::pausar()
{
    cout << "Pressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string Utils::getFileContent(string fileName)
{
 string fileContent = "";
	try
		{
		ifstream inputFile(fileName);
		stringstream buffer;

		if (!inputFile.is_open())
			{
			throw runtime_error("Failed to open the file: " + fileName);
			}

		buffer << inputFile.rdbuf(); // Read entire file into the buffer
		inputFile.close();
		fileContent = buffer.str();
		}
	catch (const exception &myException)
		{
		Utils::printMessage("Unexpected problem: " + string(myException.what()));
		}
    return fileContent; 

}