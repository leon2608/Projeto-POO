#include <iostream>
#include <string>
#include <vector>

#include "SerieController.h"
#include "Controller.h"
#include "../utils/Menu.h"
#include "../utils/Utils.h"
#include "../data/dao/MemorySerieDao.h"

Controller::Controller()
{
    memoryDBConnection = new MemoryDBConnection();
    mariaDBConnection = new MariaDBConnection();
    serieDao = new MemorySerieDao(memoryDBConnection);  
    serieController = new SerieController(memoryDBConnection, mariaDBConnection, serieDao);
    utils = new Utils();
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
}

void Controller::actionReports()
{
    serieController->launchActionsReports();
}

void Controller::actionHelp()
{
    // TODO: Implement actionHelp method
}

void Controller::actionCredits()
{
    // TODO: Implement actionCredits method
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
