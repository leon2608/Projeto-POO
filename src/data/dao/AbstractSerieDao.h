#ifndef ABSTRACT_SERIE_DAO_H
#define ABSTRACT_SERIE_DAO_H

#include <vector>
#include "../../model/Serie.h"

using namespace std;

class AbstractSerieDao
{
public:
    AbstractSerieDao() {}
    virtual ~AbstractSerieDao() {}

    virtual vector<Serie *> getSerieList() = 0;
    virtual Serie *getSerieById(int id) = 0;
    virtual void addSerie(Serie &serie) = 0;
    virtual void removeSerie(Serie &serie) = 0;
    virtual void updateSerieName(int serieId, string newName) = 0;
    virtual void updateSerieYear(int serieId, int newYear) = 0;
    virtual void updateSerieSeason(int serieId, int newSeason) = 0;
    virtual void updateSerieEpisodeCount(int serieId, int newEpisodeCount) = 0;
    virtual void updateSerieMainActors(int serieId, string newMainActors) = 0;
    virtual void updateSerieMainCharacters(int serieId, string newMainCharacters) = 0;
    virtual void updateSerieNetwork(int serieId, string newNetwork) = 0;
    virtual void updateSerieRating(int serieId, int newRating) = 0;
};

#endif // ABSTRACT_SERIE_DAO_H