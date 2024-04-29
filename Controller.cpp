/*
 * start.cpp
 *
 * Created on: April 29, 2024
 *       Author: Leonardo, Vinicius, Luis and Gabriel
 */

#include <iostream>
#include <string>
#include <vector>

#include "Controller.h"
#include "Menu.h"
#include "Menu.cpp"
#include "Utils.h"

Controller::~Controller()
{
    // nothing to do
}

void Controller::start()
{
    vector<string> menuItens{"Séries", "Relatórios", "Ajuda", "Créditos", "Sair"};
    vector<void (Controller::*)()> functions{&Controller::actionSelect};
    launchActions("Menu Principal", menuItens, functions);
}

void Controller::launchActions(string title, vector<string> menuItens, vector<void (Controller::*)()> functions)
{
    try
    {
        Menu menu(menuItens, title, "Your option: ");
        menu.setSymbol("*");

        while (int choice = menu.getChoice())
        {
            (this->*functions.at(choice - 1))();
        }
    }
    catch (const exception &myException)
    {
        Utils::printMessage("Unexpected problem launching actions. " + string(myException.what()));
    }
}
