#include "SerieController.h"
#include "../model/Serie.h"
#include "../utils/Menu.h"

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
    this->utils = new Utils();

    // Serie controller constructor for MariaDB
    // this->mariaDBConnection = new MariaDBConnection();
    // this->serieDao = new MariaDBSerieDao(mariaDBConnection);

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
void SerieController::launchActionsCredits(void)
{
    int widthName = 30;
    int widthRa = 6;
    int widthCreditsOverall = widthName + widthRa;

    cout << "+" << string((widthCreditsOverall + 5), '-') << "+" << endl;
    cout << "| " << left << setw(widthCreditsOverall + 3) << "Lista de desenvolvedores do Projeto" << " |" << endl;
    cout << "+" << string((widthName + 2), '-') << "+" << string((widthRa + 2), '-') << "+" << endl;
    cout << "| " << left << setw(widthName) << "Nomes" << " | " << setw(widthRa) << "RA's" << " |" << endl;
    cout << "+" << string((widthName + 2), '-') << "+" << string((widthRa + 2), '-') << "+" << endl;
    cout << "| " << left << setw(widthName) << "Luiz Henrique Firmino de Jesus" << " | " << setw(widthRa) << "176204" << " |" << endl;
    cout << "| " << left << setw(widthName) << "Vinicius Duarte Cegalla" << " | " << setw(widthRa) << "247095" << " |" << endl;
    cout << "| " << left << setw(widthName) << "Leonardo Rodrigues Da Silva" << " | " << setw(widthRa) << "251773" << " |" << endl;
    cout << "| " << left << setw(widthName) << "Gabriel Dias Ponsoni" << " | " << setw(widthRa) << "257103" << " |" << endl;
    cout << "+" << string((widthName + 2), '-') << "+" << string((widthRa + 2), '-') << "+" << endl;

    utils->systemPause();
    utils->clearScreen();
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
    }
}

void SerieController::actionSeriesRemoveRegister()
{
}

void SerieController::actionReportsOrderByTitle(void)
{
    utils->clearScreen();
    cout << serieDao->getSerieListOrderedByTitle() << endl;
    utils->systemPause();
    utils->clearScreen();
}

void SerieController::actionReportsOrderByNetwork(void)
{
    utils->clearScreen();
    cout << serieDao->getSerieListOrderedByNetwork() << endl;
    utils->systemPause();
    utils->clearScreen();
}

void SerieController::actionReportsOrderByYear(void)
{
    utils->clearScreen();
    cout << serieDao->getSerieListOrderedByYear() << endl;
    utils->systemPause();
    utils->clearScreen();
}

void SerieController::actionReportsOrderByRating(void)
{
    utils->clearScreen();
    cout << serieDao->getSerieListOrderedByRating() << endl;
    utils->systemPause();
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
    cout << "Digite a avaliação da série:" << endl;
    cin >> rating;
    utils->clearScreen();

    return new Serie(lastSerieId, serieName, releaseYear, season, episodeCount, mainActors, mainCharacters, network, rating);
}

void SerieController::updateName(int id)
{
    string newName;
    cout << "Digite o novo nome: ";
    getline(cin, newName);
    serieDao->updateSerieName(id, newName);
}

void SerieController::updateYear(int id)
{
    int newYear;
    cout << "Digite o novo ano de lançamento: ";
    cin >> newYear;
    serieDao->updateSerieYear(id, newYear);
}

void SerieController::updateSeason(int id)
{
    int newSeason;
    cout << "Digite a nova temporada: ";
    cin >> newSeason;
    serieDao->updateSerieSeason(id, newSeason);
}

void SerieController::updateEpisodeCount(int id)
{
    int newEpisodeCount;
    cout << "Digite a nova contagem de episódios: ";
    cin >> newEpisodeCount;
    serieDao->updateSerieEpisodeCount(id, newEpisodeCount);
}

void SerieController::updateMainActors(int id)
{
    string newMainActors;
    cout << "Digite os novos atores principais: ";
    getline(cin, newMainActors);
    serieDao->updateSerieMainActors(id, newMainActors);
}

void SerieController::updateMainCharacters(int id)
{
    string newMainCharacters;
    cout << "Digite os novos personagens principais: ";
    getline(cin, newMainCharacters);
    serieDao->updateSerieMainCharacters(id, newMainCharacters);
}

void SerieController::updateNetwork(int id)
{
    string newNetwork;
    cout << "Digite o novo canal de exibição: ";
    getline(cin, newNetwork);
    serieDao->updateSerieNetwork(id, newNetwork);
}

void SerieController::updateRating(int id)
{
    int newRating;
    cout << "Digite a nova avaliação: ";
    cin >> newRating;
    serieDao->updateSerieRating(id, newRating);
}
