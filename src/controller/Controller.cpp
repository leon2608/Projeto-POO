#include <iostream>
#include <string>
#include <vector>

#include "Controller.h"
#include "../utils/Menu.h"
#include "../utils/Utils.h"

Controller::~Controller() {
}

void Controller::start()
{
    vector<string> menuItens{"Séries", "Relatórios", "Ajuda", "Créditos", "Sair"};
    vector<void (Controller::*)()> functions{&Controller::actionSelect};
    launchActions("Menu Principal", menuItens, functions);
}

void Controller::actionSelect()
{
    // TODO: Implement actionSelect method
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
