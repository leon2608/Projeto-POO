#ifndef ABSTRACT_SERIE_DAO_H
#define ABSTRACT_SERIE_DAO_H

#include "../../model/Serie.h"
#include <vector>

using namespace std;

class AbstractSerieDao
{
public:
    AbstractSerieDao() {}
    virtual ~AbstractSerieDao() {}

    virtual vector<Serie *> getSerieList() const = 0;
    virtual vector<Serie *> getSerieListOrderedByTitle() const = 0;
    virtual vector<Serie *> getSerieListOrderedByNetwork() const = 0;
    virtual vector<Serie *> getSerieListOrderedByYear() const = 0;
    virtual vector<Serie *> getSerieListOrderedByRating() const = 0;
    virtual Serie *getSerieById(int serieId) const = 0;
    virtual void addSerie(Serie *serie) = 0;
    virtual void removeSerie(int serieId) = 0;
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