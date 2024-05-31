#include <iostream>
#include <string>
#include <vector>

#include "Controller.h"
#include "../utils/Menu.h"


Controller::Controller()
{
    this->serieController = new SerieController();
    this->utils = new Utils();
    
}
Controller::~Controller()
{
}

void Controller::start()
{
    vector<string> menuItens{"Séries", "Relatórios", "Ajuda", "Créditos", "Sair"};
    vector<void (Controller::*)()> functions{&Controller::actionSeries, &Controller::actionReports, &Controller::actionHelp, &Controller::actionCredits};
    launchActions("Menu Principal", menuItens, functions);
}

void Controller::actionSeries()
{
    utils->clearScreen();
    serieController->launchActionsSeries();
    utils->clearScreen();
}

void Controller::actionReports()
{
    this->serieController->launchActionsReports();
}

void Controller::actionHelp()
{
}

void Controller::actionCredits()
{
    utils->clearScreen();
    this->serieController->launchActionsCredits();
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
