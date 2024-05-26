#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

class Utils final
{
public:
    Utils();
    virtual ~Utils();
    static void printMessage(string text);
    static void printFramedMessage(string text, string symbol, int length);
    static string replicate(string text, int times);
    static void clearScreen();
    static void pause();
};

#endif // UTILS_H
