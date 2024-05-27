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
    int widthSerieName = serie.serieName.length();
    int widthMainActors = serie.mainActors.length();
    int widthMainCharacters = serie.mainCharacters.length();
    int widthNetwork = serie.network.length();

    int widthInternalId = to_string(serie.internalId).length();
    int widthReleaseYear = to_string(serie.releaseYear).length();
    int widthSeason = to_string(serie.season).length();
    int widthRating = to_string(serie.rating).length();

    int widthRight = max({widthMainActors, widthMainCharacters, widthNetwork,
                           widthInternalId, widthReleaseYear, widthSeason, widthRating});
    int widthLeft = 23;
    int widthOverall = widthRight + widthLeft;

    if (widthOverall < serie.serieName.length())  
    {
        widthRight += (serie.serieName.length() - widthOverall);
        widthOverall = serie.serieName.length();
    }

    os << "+" << string((widthOverall + 2), '-') << "+" << endl;
    os << "| " << left << setw(widthOverall) << serie.serieName << " |" << endl;
    os << "+" << string((widthOverall + 2), '-') << "+" << endl;
    os << "| " << left << setw(widthLeft) << "ID interno: "              << right << setw(widthRight) << serie.internalId     << " |" << endl;
    os << "| " << left << setw(widthLeft) << "Ano de lancamento: "       << right << setw(widthRight) << serie.releaseYear    << " |" << endl;
    os << "| " << left << setw(widthLeft) << "Temporadas: "              << right << setw(widthRight) << serie.season         << " |" << endl;
    os << "| " << left << setw(widthLeft) << "Numero de episodios: "     << right << setw(widthRight) << serie.episodeCount   << " |" << endl;
    os << "| " << left << setw(widthLeft) << "Ator/Atriz principal: "    << right << setw(widthRight) << serie.mainActors     << " |" << endl;
    os << "| " << left << setw(widthLeft) << "Personagem principal: "    << right << setw(widthRight) << serie.mainCharacters << " |" << endl;
    os << "| " << left << setw(widthLeft) << "Canal/Streaming: "         << right << setw(widthRight) << serie.network        << " |" << endl;
    os << "| " << left << setw(widthLeft) << "Nota de classificacao: "   << right << setw(widthRight) << serie.rating         << " |" << endl;
    os << "+" << string((widthOverall + 2), '-') << "+" << endl;

    return os;
}