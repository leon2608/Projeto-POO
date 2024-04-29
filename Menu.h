/*
 * Menu.h
 *
 * Created on: April 29, 2024
 *       Author: Leonardo, Vinicius, Luis and Gabriel
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>

using namespace std;

class Menu
{
private:
    vector<string> &itens;
    string title;
    string message;

    string symbol;
    bool repeatList;
    int width;
    bool zeroForLastOpt;

    const bool isNotAvalidChoice (unsigned long choice) const;
    const string replicate(string text, int times) const;
    const string makeDecorator();

public:
    Menu(vector<string> &itens, string title = "Menu", string message = "Option");
    virtual ~Menu();
    
    const int getChoice();

    void setWidth (int width = 0);
    bool isRepeatList() const;
    void setSymbol(const string &symbol = "-");
    void setRepeatList(bool repeatList = false);
    void setZeroForLastOpt(bool zeroForLastOpt = true);
};

#endif

// Fim do arquivo!