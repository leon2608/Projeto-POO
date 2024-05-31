#include "Serie.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

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
    int widthEpisodeCount = to_string(serie.episodeCount).length();
    int widthRating = to_string(serie.rating).length();

    int widthRight = max({widthMainActors, widthMainCharacters, widthNetwork,
                           widthInternalId, widthReleaseYear, widthSeason, widthEpisodeCount, widthRating});
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

ostream& operator<<(ostream& os, const vector<Serie*>& series)
{
    int widthInternalId = 10;
    int widthSerieName = 9;
    int widthReleaseYear = 11;
    int widthSeason = 6;
    int widthEpisodeCount = 12;
    int widthMainActors = 10;
    int widthMainCharacters = 14; 
    int widthNetwork = 7;
    int widthRating = 6;
    
    int i;
    size_t total = series.size();

    for (const Serie* serie : series) 
    {
    if(widthInternalId < to_string(serie->internalId).length())
        widthInternalId = to_string(serie->internalId).length();

    if(widthSerieName < serie->serieName.length())
        widthSerieName = serie->serieName.length();

    if(widthReleaseYear < to_string(serie->releaseYear).length())
        widthReleaseYear = to_string(serie->releaseYear).length();

    if(widthSeason < to_string(serie->season).length())
        widthSeason = to_string(serie->season).length();

    if(widthEpisodeCount < to_string(serie->episodeCount).length())
        widthEpisodeCount = to_string(serie->episodeCount).length();
    
    if(widthMainActors < (serie->mainActors).length())
        widthMainActors = (serie->mainActors).length();
    
    if(widthMainCharacters < (serie->mainCharacters).length())
        widthMainCharacters = (serie->mainCharacters).length();
    
    if(widthNetwork < (serie->network).length())
        widthNetwork = (serie->network).length();

    if(widthRating < to_string(serie->rating).length())
        widthRating = to_string(serie->rating).length();
    }

    os  << "+" << string((widthInternalId+2), '-') << "+" << string((widthSerieName+2), '-')
        << "+" << string((widthReleaseYear+2), '-') << "+" << string((widthSeason+2), '-')
        << "+" << string((widthEpisodeCount+2), '-') << "+" << string((widthMainActors+2), '-')
        << "+" << string((widthMainCharacters+2), '-') << "+" << string((widthNetwork+2), '-') 
        << "+" << string((widthRating+2), '-') << "+"<< endl;

    os  << left << "| " << setw(widthInternalId)    << "internalID"
                << " | " << setw(widthSerieName)    << "serieName"
                << " | " << setw(widthReleaseYear)  << "releaseYear"
                << " | " << setw(widthSeason)       << "season"
                << " | " << setw(widthEpisodeCount) << "episodeCount"
                << " | " << setw(widthMainActors)   << "mainActors"
                << " | " << setw(widthMainCharacters) << "mainCharacters"
                << " | " << setw(widthNetwork)      << "network"
                << " | " << setw(widthRating)       << "rating"
                << " |" << endl;

    os  << "+" << string((widthInternalId+2), '-') << "+" << string((widthSerieName+2), '-')
        << "+" << string((widthReleaseYear+2), '-') << "+" << string((widthSeason+2), '-')
        << "+" << string((widthEpisodeCount+2), '-') << "+" << string((widthMainActors+2), '-')
        << "+" << string((widthMainCharacters+2), '-') << "+" << string((widthNetwork+2), '-') 
        << "+" << string((widthRating+2), '-') << "+"<< endl;

    for (const Serie* serie : series) {
        os << left  << "| " << setw(widthInternalId)       << serie->internalId
                    << " | " << setw(widthSerieName)       << serie->serieName
                    << " | " << setw(widthReleaseYear)     << serie->releaseYear
                    << " | " << setw(widthSeason)          << serie->season
                    << " | " << setw(widthEpisodeCount)    << serie->episodeCount
                    << " | " << setw(widthMainActors)      << serie->mainActors
                    << " | " << setw(widthMainCharacters)  << serie->mainCharacters
                    << " | " << setw(widthNetwork)         << serie->network
                    << " | " << setw(widthRating)          << serie->rating << " |" << endl;
    }

    os    << "+" << string((widthInternalId+2), '-') << "+" << string((widthSerieName+2), '-')
            << "+" << string((widthReleaseYear+2), '-') << "+" << string((widthSeason+2), '-')
            << "+" << string((widthEpisodeCount+2), '-') << "+" << string((widthMainActors+2), '-')
            << "+" << string((widthMainCharacters+2), '-') << "+" << string((widthNetwork+2), '-') 
            << "+" << string((widthRating+2), '-') << "+"<< endl; 

    return os;
}