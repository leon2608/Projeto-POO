#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iomanip>

#include "../model/Serie.h"
#include "../data/dao/MemorySerieDao.h"
#include "../data/dao/AbstractSerieDao.h"
#include "../data/connection/MemoryDBConnection.h"
#include "SerieController.h"
#include "../utils/Menu.h"
#include "../utils/Utils.h"

SerieController::SerieController()
{
    // this->mariaDBConnection = new MariaDBConnection();
    this->memoryDBConnection = new MemoryDBConnection();
    this->serieDao = new MemorySerieDao(memoryDBConnection);
    this->utils = new Utils();

    serieDao->addSerie(new Serie(1, "Mystic Falls", 2021, 3, 30, "Jane Doe, John Smith", "Alice, Bob", "ABC", 8));
    serieDao->addSerie(new Serie(2, "Galactic Wars", 2020, 2, 24, "Emily Clark, George Doe", "Captain Rex, Zara", "Netflix", 7));
    serieDao->addSerie(new Serie(3, "Time Travelers", 2019, 4, 40, "Sarah Brown, Michael White", "Liam, Emma", "HBO", 9));
    serieDao->addSerie(new Serie(4, "Haunted Manor", 2022, 1, 10, "Anna Black, Chris Green", "Nina, Jack", "AMC", 6));
    serieDao->addSerie(new Serie(5, "Cyber City", 2023, 2, 20, "David Miller, Laura Wilson", "Max, Lucy", "Amazon Prime", 8));
    serieDao->addSerie(new Serie(6, "Royalty", 2021, 5, 50, "Olivia Jones, Robert Brown", "Queen Elizabeth, Prince Arthur", "BBC", 7));
    serieDao->addSerie(new Serie(7, "Wild West", 2020, 3, 30, "William Taylor, Emma Stone", "Sheriff Bob, Annie", "Hulu", 8));
    serieDao->addSerie(new Serie(8, "Future Tech", 2018, 4, 35, "Sophia Lee, Ryan Harris", "Dr. X, Agent Y", "CBS", 9));
    serieDao->addSerie(new Serie(9, "Island Mystery", 2022, 1, 12, "Jessica Davis, Mark Robinson", "Hannah, Tom", "NBC", 6));
}

SerieController::~SerieController()
{
}

void SerieController::launchActionsSeries(void)
{
    vector<string> menuItens{"Adicionar Registro", "Restaurar registro", "Editar Registro", "Remover Registro", "Sair"};
    vector<void (SerieController::*)()> functions{&SerieController::actionSeriesAddRegister, &SerieController::actionSeriesRestoreRegister, &SerieController::actionSeriesEditRegister, &SerieController::actionSeriesRemoveRegister};
    launchActions("Menu Registro", menuItens, functions);
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
        utils->systemPause();
        utils->clearScreen();
    }
    else
    {
        cout << "Serie name is empty. Operation canceled!" << endl;
    }
}

void SerieController::actionSeriesRestoreRegister()
{
    utils->clearScreen();
    SerieController registro;
    Serie *serie;
    int serieId;
    utils->clearScreen();
    cout << "Digite o ID da série que deseja encontrar:" << endl;
    cin >> serieId;
    serie = serieDao->getSerieById(serieId);
    if (serie != nullptr)
    {
        utils->clearScreen();
        cout << *serie;
        utils->systemPause();
        utils->clearScreen();
    }
    else
    {
        utils->clearScreen();
        cout << "Nenhum registro foi encontrado com esse ID." << endl;
        utils->systemPause();
        utils->clearScreen();
    }
}

void SerieController::actionSeriesEditRegister()
{
    utils->clearScreen();
    int serieId;
    vector<string> menuItens{
        "Editar Nome",
        "Editar Ano de Lançamento",
        "Editar Temporada",
        "Editar Contagem de Episódios",
        "Editar Atores Principais",
        "Editar Personagens Principais",
        "Editar Canal de Exibição",
        "Editar Avaliação",
        "Sair"};

    vector<Serie *> series;
    Serie *serie;
    series = serieDao->getSerieList();
    cout << series << endl;
    cout << "Digite o ID da série que você deseja alterar:" << endl;
    cin >> serieId;
    serie = serieDao->getSerieById(serieId);
    if (serie != nullptr)
    {
        utils->clearScreen();
        cout << *serie << endl;
        vector<function<void(int)>> functionsEdit{
            [this](int id)
            {
                string newName;
                cout << "Digite o novo nome: ";
                cin.ignore();
                getline(cin, newName);
                serieDao->updateSerieName(id, newName);
            },
            [this](int id)
            {
                int newYear;
                cout << "Digite o novo ano de lançamento: ";
                cin >> newYear;
                serieDao->updateSerieYear(id, newYear);
            },
            [this](int id)
            {
                int newSeason;
                cout << "Digite a nova temporada: ";
                cin >> newSeason;
                serieDao->updateSerieSeason(id, newSeason);
            },
            [this](int id)
            {
                int newEpisodeCount;
                cout << "Digite a nova contagem de episódios: ";
                cin >> newEpisodeCount;
                serieDao->updateSerieEpisodeCount(id, newEpisodeCount);
            },
            [this](int id)
            {
                string newMainActors;
                cout << "Digite os novos atores principais: ";
                cin.ignore();
                getline(cin, newMainActors);
                serieDao->updateSerieMainActors(id, newMainActors);
            },
            [this](int id)
            {
                string newMainCharacters;
                cout << "Digite os novos personagens principais: ";
                cin.ignore();
                getline(cin, newMainCharacters);
                serieDao->updateSerieMainCharacters(id, newMainCharacters);
            },
            [this](int id)
            {
                string newNetwork;
                cout << "Digite o novo canal de exibição: ";
                cin.ignore();
                getline(cin, newNetwork);
                serieDao->updateSerieNetwork(id, newNetwork);
            },
            [this](int id)
            {
                int newRating;
                cout << "Digite a nova avaliação: ";
                cin >> newRating;
                serieDao->updateSerieRating(id, newRating);
            }};

        Menu menu(menuItens, "Qual informação você deseja alterar?", "Your option: ");
        menu.setSymbol("*");

        while (int choice = menu.getChoice())
        {
            functionsEdit[choice - 1](serieId);
        }
    }
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
    utils->clearScreen();

    return new Serie(lastSerieId, serieName, releaseYear, season, episodeCount, mainActors, mainCharacters, network, rating);
}

const bool SerieController::isNotAValidChoice(unsigned long choice, vector<string> itens) const
{
    return ((choice < 0) || (choice > (itens.size() - 1)));
}