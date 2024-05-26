#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <iomanip>

#include "../model/Serie.h"
#include "../data/dao/MemorySerieDao.h"
#include "../data/dao/AbstractSerieDao.h"
#include "SerieController.h"
#include "../utils/Menu.h"
#include "../utils/Utils.h"

SerieController::SerieController()
{
    // this->mariaDBConnection = new MariaDBConnection();
    this->memoryDBConnection = new MemoryDBConnection();
    this->serieDao = new MemorySerieDao(memoryDBConnection);
    this->utils = new Utils();
}

SerieController::~SerieController()
{
}

void SerieController::launchActionsSeries(void)
{
    vector<string> menuItens{"Adicionar Registro", "Restaurar registro", "Editar Registro", "Remover Registro", "Sair"};
    vector<void (SerieController::*)()> functions{&SerieController::actionSeriesAddRegister, &SerieController::actionSeriesRestoreRegister, &SerieController::actionSeriesEditRegister, &SerieController::actionSeriesRemoveRegister};
    launchActions("Menu Principal", menuItens, functions);
}

void SerieController::launchActionsReports(void)
{
}

void SerieController::actionSeriesAddRegister()
{
    SerieController registro;
    Serie *newSerie = registro.addRegister();

    if (!(newSerie->getSerieName()).empty())
    {
        utils->clearScreen();
        this->serieDao->addSerie(newSerie);
        cout << "Série cadastrada com sucesso!!" << endl;
        cout << *newSerie;
        cout <<"Digite 'Enter' para continuar..." << endl;
        getchar();
        utils->clearScreen();
    }
    else
    {
        cout << "Serie name is empty. Operation canceled!" << endl;
    }
}

void SerieController::actionSeriesRestoreRegister()
{
}

void SerieController::actionSeriesEditRegister()
{
}

void SerieController::actionSeriesRemoveRegister()
{
}

void SerieController::actionReportsOrderByTitle(void)
{
}

void SerieController::actionReportsOrderByNetwork(void)
{
}

void SerieController::actionReportsOrderByYear(void)
{
}

void SerieController::actionReportsOrderByRating(void)
{
}

void SerieController::launchActions(string title, vector<string> menuItens, vector<void (SerieController::*)()> functions)
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

Serie *SerieController::addRegister()
{
    int static lastSerieId;
    string serieName;
    int releaseYear;
    int season;
    int episodeCount;
    string mainActors;
    string mainCharacters;
    string network;
    int rating;

    utils->clearScreen();
    cout << "Inclusão de uma nova série:" << endl;
    cout << "Digite o nome da série:" << endl;
    getline(cin, serieName);
    utils->clearScreen();
    cout << "Digite o ano de lançamento da série:" << endl;
    cin >> releaseYear;
    cin.ignore();
    utils->clearScreen();
    cout << "Digite o número de temporadas da série:" << endl;
    cin >> season;
    cin.ignore();
    utils->clearScreen();
    cout << "Digite o número de episódios da série:" << endl;
    cin >> episodeCount;
    cin.ignore();
    utils->clearScreen();
    cout << "Digite os atores principais da série:" << endl;
    getline(cin, mainActors);
    utils->clearScreen();
    cout << "Digite os personagens principais da série:" << endl;
    getline(cin, mainCharacters);
    utils->clearScreen();
    cout << "Digite a rede da série:" << endl;
    getline(cin, network);
    utils->clearScreen();
    cout << "Digite a avaliação da série:" << endl;
    cin >> rating;
    cin.ignore();
    utils->clearScreen();

    return new Serie(lastSerieId, serieName, releaseYear, season, episodeCount, mainActors, mainCharacters, network, rating);
}
