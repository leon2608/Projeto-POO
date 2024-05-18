#include <iostream>
#include <string>

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
