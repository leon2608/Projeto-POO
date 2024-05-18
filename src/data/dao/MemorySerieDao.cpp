#include <algorithm>

#include "MemorySerieDao.h"
#include "../connection/MemoryDBConnection.h"
#include "../../model/Serie.h"

int MemorySerieDao::lastEntryId = 0;

MemorySerieDao::MemorySerieDao(MemoryDBConnection *connection) : connection(connection)
{
}

MemorySerieDao::~MemorySerieDao() {}

vector<Serie *> MemorySerieDao::getAllSeries()
{
    return (connection->getSerieList());
}

Serie *MemorySerieDao::getSerieById(int serieId)
{
    vector<Serie *> &series = connection->getSerieList();
    vector<Serie *>::iterator serieIterator = series.begin();
    Serie *buffer = NULL;
    bool found = false;

    while ((!found) && (serieIterator != series.end()))
    {
        if ((*serieIterator)->getInternalId() == serieId)
        {
            found = true;
            buffer = *serieIterator;
        }
        serieIterator++;
    }
    return (buffer);
}

void MemorySerieDao::add(Serie *serie)
{
    serie->setSerieId(++lastEntryId);
    (connection->getSerieList()).push_back(serie);
}

void MemorySerieDao::remove(int serieId)
{
    vector<Serie *> &series = connection->getSerieList();
    vector<Serie *>::iterator serieIterator = series.begin();
    bool found = false;

    while ((!found) && (serieIterator != series.end()))
    {
        if ((*serieIterator)->getInternalId() == serieId)
        {
            found = true;
            delete *serieIterator;
            series.erase(serieIterator);
        }
        serieIterator++;
    }
}

void MemorySerieDao::updateName(int serieId, string newName)
{
    Serie *serie = getSerieById(serieId);
    serie->setSerieName(newName);
}

void MemorySerieDao::updateYear(int serieId, int newYear)
{
    Serie *serie = getSerieById(serieId);
    serie->setReleaseYear(newYear);
}

void MemorySerieDao::updateSeason(int serieId, int newSeason)
{
    Serie *serie = getSerieById(serieId);
    serie->setSeason(newSeason);
}

void MemorySerieDao::updateEpisodeCount(int serieId, int newEpisodeCount)
{
    Serie *serie = getSerieById(serieId);
    serie->setEpisodeCount(newEpisodeCount);
}

void MemorySerieDao::updateMainActors(int serieId, string newMainActors)
{
    Serie *serie = getSerieById(serieId);
    serie->setMainActors(newMainActors);
}

void MemorySerieDao::updateMainCharacters(int serieId, string newMainCharacters)
{
    Serie *serie = getSerieById(serieId);
    serie->setMainCharacters(newMainCharacters);
}

void MemorySerieDao::updateNetwork(int serieId, string newNetwork)
{
    Serie *serie = getSerieById(serieId);
    serie->setNetwork(newNetwork);
}

void MemorySerieDao::updateRating(int serieId, int newRating)
{
    Serie *serie = getSerieById(serieId);
    serie->setRating(newRating);
}
