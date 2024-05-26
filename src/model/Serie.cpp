#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

#include "Serie.h"

using namespace std;

Serie::Serie(int internalId, string serieName, int releaseYear, int season,
             int episodeCount, string mainActors, string mainCharacters,
             string network, int rating)
{
    this->internalId = internalId;
    this->serieName = serieName;
    this->releaseYear = releaseYear;
    this->season = season;
    this->episodeCount = episodeCount;
    this->mainActors = mainActors;
    this->mainCharacters = mainCharacters;
    this->network = network;
    this->rating = rating;
}
Serie::~Serie()
{
}

int Serie::getInternalId()
{
    return this->internalId;
}

string Serie::getSerieName()
{
    return this->serieName;
}

int Serie::getReleaseYear()
{
    return this->releaseYear;
}

int Serie::getSeason()
{
    return this->season;
}

int Serie::getEpisodeCount()
{
    return this->episodeCount;
}

string Serie::getMainActors()
{
    return this->mainActors;
}

string Serie::getMainCharacters()
{
    return this->mainCharacters;
}

string Serie::getNetwork()
{
    return this->network;
}

int Serie::getRating()
{
    return this->rating;
}

void Serie::setSerieName(string name)
{
    this->serieName = name;
}

void Serie::setReleaseYear(int year)
{
    this->releaseYear = year;
}

void Serie::setSeason(int season)
{
    this->season = season;
}

void Serie::setEpisodeCount(int espisodeNumber)
{
    this->episodeCount = espisodeNumber;
}

void Serie::setMainActors(string mainActors)
{
    this->mainActors = mainActors;
}

void Serie::setMainCharacters(string getMainCharacters)
{
    this->mainCharacters = mainCharacters;
}

void Serie::setNetwork(string network)
{
    this->network = network;
}

void Serie::setRating(int rating)
{
    this->rating = rating;
}

void Serie::setSerieId(int internalId)
{
    this->internalId = internalId;
}

ostream& operator<<(std::ostream& os, const Serie& serie) 
{
    int width_SerieName = serie.serieName.length();
    int width_MainActors = serie.mainActors.length();
    int width_MainCharacters = serie.mainCharacters.length();
    int width_Network = serie.network.length();

    int width_left = 23;
    int width_right = max({width_SerieName, width_MainActors, width_MainCharacters, width_Network});
    int width_overall = width_right + width_left;

    if (width_overall < serie.serieName.length())  
    {
        width_left += (serie.serieName.length() - width_overall) + 2;
        width_overall = serie.serieName.length();
    }

    os << "+" << string((width_overall + 2), '-') << "+" << endl;
    os << "| " << left << setw(width_overall) << serie.serieName << " |" << endl;
    os << "+" << string((width_overall + 2), '-') << "+" << endl;
    os << "| " << left << setw(width_left) << "ID interno: "              << right << setw(width_right) << serie.internalId     << " |" << endl;
    os << "| " << left << setw(width_left) << "Ano de lancamento: "       << right << setw(width_right) << serie.releaseYear    << " |" << endl;
    os << "| " << left << setw(width_left) << "Temporadas: "              << right << setw(width_right) << serie.season         << " |" << endl;
    os << "| " << left << setw(width_left) << "Numero de episodios: "     << right << setw(width_right) << serie.episodeCount   << " |" << endl;
    os << "| " << left << setw(width_left) << "Ator/Atriz principal: "    << right << setw(width_right) << serie.mainActors     << " |" << endl;
    os << "| " << left << setw(width_left) << "Personagem principal: "    << right << setw(width_right) << serie.mainCharacters << " |" << endl;
    os << "| " << left << setw(width_left) << "Canal/Streaming: "         << right << setw(width_right) << serie.network        << " |" << endl;
    os << "| " << left << setw(width_left) << "Nota de classificacao: "   << right << setw(width_right) << serie.rating         << " |" << endl;
    os << "+" << string((width_overall + 2), '-') << "+" << endl;

    return os;
}