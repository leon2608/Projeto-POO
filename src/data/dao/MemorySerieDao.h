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
    virtual vector<Serie *> getAllSeries();
    virtual Serie *getSerieById(int serieId);
    virtual void add(Serie *serie);
    virtual void remove(int serieId);
    virtual void updateName(int serieId, string newName);
    virtual void updateYear(int serieId, int newYear);
    virtual void updateSeason(int serieId, int newSeason);
    virtual void updateEpisodeCount(int serieId, int newEpisodeCount);
    virtual void updateMainActors(int serieId, string newMainActors);
    virtual void updateMainCharacters(int serieId, string newMainCharacters);
    virtual void updateNetwork(int serieId, string newNetwork);
    virtual void updateRating(int serieId, int newRating);
};

#endif // MEMORY_SERIE_DAO_H