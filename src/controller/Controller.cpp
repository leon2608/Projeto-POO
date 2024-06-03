#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
    utils->clearScreen();
    this->serieController->launchActionsReports();
    utils->clearScreen();
}

void Controller::actionHelp()
{
    utils->clearScreen();
    string conteudo = utils->getFileContent("STVSHelp.txt");
    utils->printFramedMessage(conteudo, "*", 137);
    utils->pausar();
    utils->clearScreen();
}

void Controller::actionCredits()
{
    int widthName = 30;
    int widthRa = 6;
    int widthCreditsOverall = widthName + widthRa;

    utils->clearScreen();
    cout << "+" << string((widthCreditsOverall+5), '-') << "+" << endl;
    cout << "| " << left << setw(widthCreditsOverall+3) << "Lista de desenvolvedores do Projeto" << " |" << endl;
    cout << "+" << string((widthName+2), '-') << "+" << string((widthRa+2), '-') << "+" << endl;
    cout << "| " << left << setw(widthName) << "Nomes" << " | " << setw(widthRa) << "RA's" << " |" << endl;
    cout << "+" << string((widthName+2), '-') << "+" << string((widthRa+2), '-') << "+" << endl;
    cout << "| " << left << setw(widthName) << "Luiz Henrique Firmino de Jesus" << " | " << setw(widthRa) << "176204" << " |" << endl;
    cout << "| " << left << setw(widthName) << "Vinicius Duarte Cegalla" << " | " << setw(widthRa) << "247095" << " |" << endl;
    cout << "| " << left << setw(widthName) << "Leonardo Rodrigues Da Silva" << " | " << setw(widthRa) << "251773" << " |" << endl;
    cout << "| " << left << setw(widthName) << "Gabriel Dias Ponsoni" << " | " << setw(widthRa) << "257103" << " |" << endl;
    cout << "+" << string((widthName+2), '-') << "+" << string((widthRa+2), '-') << "+" << endl;

    utils->pausar();
    utils->clearScreen();
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