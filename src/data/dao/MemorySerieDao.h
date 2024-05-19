#ifndef MEMORY_SERIE_DAO_H
#define MEMORY_SERIE_DAO_H

#include "AbstractSerieDao.h"
#include "../connection/MemoryDBConnection.h"

class MemorySerieDao : public AbstractSerieDao
{
private:
    MemoryDBConnection *connection;
    static int lastEntryId;

public:
    MemorySerieDao(MemoryDBConnection *memoryDBConnection);
    virtual ~MemorySerieDao();
    
    virtual vector<Serie *> getSerieList();
    virtual Serie *getSerieById(int serieId);
    virtual void addSerie(Serie *serie);
    virtual void removeSerie(int serieId);
    virtual void updateSerieName(int serieId, string newName);
    virtual void updateSerieYear(int serieId, int newYear);
    virtual void updateSerieSeason(int serieId, int newSeason);
    virtual void updateSerieEpisodeCount(int serieId, int newEpisodeCount);
    virtual void updateSerieMainActors(int serieId, string newMainActors);
    virtual void updateSerieMainCharacters(int serieId, string newMainCharacters);
    virtual void updateSerieNetwork(int serieId, string newNetwork);
    virtual void updateSerieRating(int serieId, int newRating);
};

#endif // MEMORY_SERIE_DAO_H