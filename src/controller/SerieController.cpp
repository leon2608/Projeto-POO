#include "SerieController.h"
#include "../model/Serie.h"
#include "../data/dao/MemorySerieDao.h"
#include "../data/dao/AbstractSerieDao.h"
#include "../data/connection/MemoryDBConnection.h"
#include "../utils/Menu.h"
#include "../utils/Utils.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <limits>

SerieController::SerieController(DataBaseSelector dataBaseSelector)
{
    this->utils = new Utils();

    this->memoryDBConnection = NULL;
    this->mariaDBConnection = NULL;
    switch (dataBaseSelector)
    {
        case DataBaseSelector::MEMORY:
        {
            // Serie controller constructor for Memory
            this->memoryDBConnection = new MemoryDBConnection();
            this->serieDao = new MemorySerieDao(memoryDBConnection);

            // Mocking data for testing purposes only (Memory)
            serieDao->addSerie(new Serie(1, "Mystic Falls", 2021, 3, 30, "Jane Doe, John Smith", "Alice, Bob", "ABC", 8));
            serieDao->addSerie(new Serie(2, "Galactic Wars", 2020, 2, 24, "Emily Clark, George Doe", "Captain Rex, Zara", "Netflix", 7));
            serieDao->addSerie(new Serie(3, "Time Travelers", 2019, 4, 40, "Sarah Brown, Michael White", "Liam, Emma", "HBO", 9));
            serieDao->addSerie(new Serie(4, "Haunted Manor", 2022, 1, 10, "Anna Black, Chris Green", "Nina, Jack", "AMC", 6));
            serieDao->addSerie(new Serie(5, "Cyber City", 2023, 2, 20, "David Miller, Laura Wilson", "Max, Lucy", "Amazon Prime", 8));
            serieDao->addSerie(new Serie(6, "Royalty", 2021, 5, 50, "Olivia Jones, Robert Brown", "Queen Elizabeth, Prince Arthur", "BBC", 7));
            serieDao->addSerie(new Serie(7, "Wild West", 2020, 3, 30, "William Taylor, Emma Stone", "Sheriff Bob, Annie", "Hulu", 8));
            serieDao->addSerie(new Serie(8, "Future Tech", 2018, 4, 35, "Sophia Lee, Ryan Harris", "Dr. X, Agent Y", "CBS", 9));
            serieDao->addSerie(new Serie(9, "Island Mystery", 2022, 1, 12, "Jessica Davis, Mark Robinson", "Hannah, Tom", "NBC", 6));

            break;
        }
        
        case DataBaseSelector::MARIADB:
        {
            // Serie controller constructor for MariaDB
            this->mariaDBConnection = new MariaDBConnection();
            this->serieDao = new MariaDBSerieDao(mariaDBConnection);
            break;
        }

        default:
        {
            throw invalid_argument("Seletor de banco de dados inválido.");
            break;
        }
    }
}

SerieController::~SerieController()
{
}

void SerieController::launchActionsSeries(void)
{
    vector<string> menuItens{
        "Adicionar Registro",
        "Restaurar registro",
        "Editar Registro",
        "Remover Registro",
        "Sair"};
    vector<void (SerieController::*)()> functions{
        &SerieController::actionSeriesAddRegister,
        &SerieController::actionSeriesRestoreRegister,
        &SerieController::actionSeriesEditRegister,
        &SerieController::actionSeriesRemoveRegister};
    launchActions("Menu Registro", menuItens, functions);
}
void SerieController::launchActionsReports(void)
{
    vector<string> menuItens{
        "Ordenar a partir do Título",
        "Ordenar a partir do Network",
        "Ordenar a partir do Ano de Lançamento",
        "Ordenar a partir da Nota",
        "Sair"};
    vector<void (SerieController::*)()> functions{
        &SerieController::actionReportsOrderByTitle,
        &SerieController::actionReportsOrderByNetwork,
        &SerieController::actionReportsOrderByYear,
        &SerieController::actionReportsOrderByRating};
    launchActions("Menu Relatorios", menuItens, functions);
}

void SerieController::launchActionsEdit(int serieId)
{
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
    vector<void (SerieController::*)(int)> functions{
        &SerieController::updateName,
        &SerieController::updateYear,
        &SerieController::updateSeason,
        &SerieController::updateMainActors,
        &SerieController::updateMainActors,
        &SerieController::updateMainCharacters,
        &SerieController::updateNetwork,
        &SerieController::updateRating};
    launchActionsInt("Qual atributo você deseja mudar?", menuItens, functions, serieId);
}

void SerieController::actionSeriesAddRegister()
{
    Serie *newSerie = addRegister();

    if (!(newSerie->getSerieName()).empty())
    {
        utils->clearScreen();
        this->serieDao->addSerie(newSerie);
        cout << "Série cadastrada com sucesso!!" << endl;
        cout << *newSerie;
        utils->pausar();
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
        utils->pausar();
        utils->clearScreen();
    }
    else
    {
        utils->clearScreen();
        cout << "Nenhum registro foi encontrado com esse ID." << endl;
        utils->pausar();
        utils->clearScreen();
    }
}

void SerieController::actionSeriesEditRegister()
{
    utils->clearScreen();
    int serieId;

    vector<Serie *> series;
    Serie *serie;
    series = serieDao->getSerieList();
    cout << series << endl;
    cout << "Digite o ID da série que você deseja alterar:" << endl;
    cin >> serieId;
    if (serie != nullptr)
    {
        utils->clearScreen();
        launchActionsEdit(serieId);
        utils->clearScreen();
    }
}

void SerieController::actionSeriesRemoveRegister()
{
    utils->clearScreen();
    int serieId;
    vector<Serie *> series;
    Serie *serie;
    series = serieDao->getSerieList();
    cout << series << endl;
    cout << "Digite o ID da série que você deseja remover:" << endl;
    cin >> serieId;
    serie = serieDao->getSerieById(serieId);
    if (serie != nullptr){
        cout << "Digite 1 se realmente deseje remover essa série " << serie->getSerieName() << " ?" << endl;
        int confirm;
        cin >> confirm;
    if (confirm != 1){
        cout << "Remoção de série cancelada." << endl;
    }else{
        utils->clearScreen();
        serieDao->removeSerie(serieId);
        utils->clearScreen();
        cout << "Remoção realizada" << endl;
        utils->pausar();
        utils->clearScreen();
        }
    }
}

void SerieController::actionReportsOrderByTitle(void)
{
    utils->clearScreen();
    cout << serieDao->getSerieListOrderedByTitle();
    utils->pausar();
    utils->clearScreen();
}

void SerieController::actionReportsOrderByNetwork(void)
{
    utils->clearScreen();
    cout << serieDao->getSerieListOrderedByNetwork();
    utils->pausar();
    utils->clearScreen();
}

void SerieController::actionReportsOrderByYear(void)
{
    utils->clearScreen();
    cout << serieDao->getSerieListOrderedByYear();
    utils->pausar();
    utils->clearScreen();
}

void SerieController::actionReportsOrderByRating(void)
{
    utils->clearScreen();
    cout << serieDao->getSerieListOrderedByRating();
    utils->pausar();
    utils->clearScreen();
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
void SerieController::launchActionsInt(string title, vector<string> menuItens, vector<void (SerieController::*)(int)> functions, int id)
{
    Serie *serie;
    serie = serieDao->getSerieById(id);
    try
    {
        Menu menu(menuItens, title, "Your option: ");
        menu.setSymbol("*");
        while (int choice = menu.getChoice())
        {
            (this->*functions.at(choice - 1))(id);
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
    do
    {
    cout << "Digite a avaliação da série:" << endl;
    cin >> rating;
    if (rating < 0 || rating > 10)
    {
        cout << "O número deve estar no intervalo de 0 a 10!" << endl;
    }
    } while (rating < 0 || rating > 10);
    utils->clearScreen();

    return new Serie(lastSerieId, serieName, releaseYear, season, episodeCount, mainActors, mainCharacters, network, rating);
}

void SerieController::updateName(int id)
{
    Serie *serie;
    serie = serieDao->getSerieById(id);
    string newName;
    cout << "Digite o novo nome: ";
    getline(cin, newName);
    serieDao->updateSerieName(id, newName);
    cout << "Série id: " << id << " após a mudança!" << endl;
    cout << *serie;
    utils->pausar();
    utils->clearScreen();
}

void SerieController::updateYear(int id)
{
    Serie *serie;
    serie = serieDao->getSerieById(id);
    int newYear;
    cout << "Digite o novo ano de lançamento: ";
    cin >> newYear;
    serieDao->updateSerieYear(id, newYear);
    cout << "Série id: " << id << " após a mudança!" << endl;
    cout << *serie;
    utils->pausar();
    utils->clearScreen();
}

void SerieController::updateSeason(int id)
{   
    Serie *serie;
    serie = serieDao->getSerieById(id);
    int newSeason;
    cout << "Digite a nova temporada: ";
    cin >> newSeason;
    serieDao->updateSerieSeason(id, newSeason);
    cout << "Série id: " << id << " após a mudança!" << endl;
    cout << *serie;
    utils->pausar();
    utils->clearScreen();
}

void SerieController::updateEpisodeCount(int id)
{
    Serie *serie;
    serie = serieDao->getSerieById(id);
    int newEpisodeCount;
    cout << "Digite a nova contagem de episódios: ";
    cin >> newEpisodeCount;
    serieDao->updateSerieEpisodeCount(id, newEpisodeCount);
    cout << "Série id: " << id << " após a mudança!" << endl;
    cout << *serie;
    utils->pausar();
    utils->clearScreen();
}

void SerieController::updateMainActors(int id)
{
    Serie *serie;
    serie = serieDao->getSerieById(id);
    string newMainActors;
    cout << "Digite os novos atores principais: ";
    getline(cin, newMainActors);
    serieDao->updateSerieMainActors(id, newMainActors);
    cout << "Série id: " << id << " após a mudança!" << endl;
    cout << *serie;
    utils->pausar();
    utils->clearScreen();
}

void SerieController::updateMainCharacters(int id)
{
    Serie *serie;
    serie = serieDao->getSerieById(id);
    string newMainCharacters;
    cout << "Digite os novos personagens principais: ";
    getline(cin, newMainCharacters);
    serieDao->updateSerieMainCharacters(id, newMainCharacters);
    cout << "Série id: " << id << " após a mudança!" << endl;
    cout << *serie;
    utils->pausar();
    utils->clearScreen();
}

void SerieController::updateNetwork(int id)
{
    Serie *serie;
    serie = serieDao->getSerieById(id);
    string newNetwork;
    cout << "Digite o novo canal de exibição: ";
    getline(cin, newNetwork);
    serieDao->updateSerieNetwork(id, newNetwork);
    cout << "Série id: " << id << " após a mudança!" << endl;
    cout << *serie;
    utils->pausar();
    utils->clearScreen();
}

void SerieController::updateRating(int id)
{
    Serie *serie;
    serie = serieDao->getSerieById(id);
    int newRating;
    cout << "Digite a nova avaliação: ";
    cin >> newRating;
    serieDao->updateSerieRating(id, newRating);
    cout << "Série id: " << id << " após a mudança!" << endl;
    cout << *serie;
    utils->pausar();
    utils->clearScreen();
}
