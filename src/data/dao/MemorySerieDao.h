#ifndef MEMORY_SERIE_DAO_H
#define MEMORY_SERIE_DAO_H

#include "AbstractSerieDao.h"
#include "../connection/MemoryDBConnection.h"

class MemorySerieDao : public AbstractSerieDao
{
private:
    MemoryDBConnection *connection;
    static int lastSerieId;

public:
    MemorySerieDao(MemoryDBConnection *memoryDBConnection);
    virtual ~MemorySerieDao();
    
    vector<Serie *> getSerieList() const override;
    vector<Serie *> getSerieListOrderedByTitle() const override;
    vector<Serie *> getSerieListOrderedByNetwork() const override;
    vector<Serie *> getSerieListOrderedByYear() const override;
    vector<Serie *> getSerieListOrderedByRating() const override;
    Serie *getSerieById(int serieId) const override;
    void addSerie(Serie *serie) override;
    void removeSerie(int serieId) override;
    void updateSerieName(int serieId, string newName) override;
    void updateSerieYear(int serieId, int newYear) override;
    void updateSerieSeason(int serieId, int newSeason) override;
    void updateSerieEpisodeCount(int serieId, int newEpisodeCount) override;
    void updateSerieMainActors(int serieId, string newMainActors) override;
    void updateSerieMainCharacters(int serieId, string newMainCharacters) override;
    void updateSerieNetwork(int serieId, string newNetwork) override;
    void updateSerieRating(int serieId, int newRating) override;
};

#endif // MEMORY_SERIE_DAO_H