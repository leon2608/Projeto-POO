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

    virtual vector<Serie *> &getSerieList() = 0;
    virtual Serie *getSerieById(int id) = 0;
    virtual void add(Serie &serie) = 0;
    virtual void remove(Serie &serie) = 0;
    virtual void updateName(int serieId, string newName) = 0;
    virtual void updateYear(int serieId, int newYear) = 0;
    virtual void updateSeason(int serieId, int newSeason) = 0;
    virtual void updateEpisodeCount(int serieId, int newEpisodeCount) = 0;
    virtual void updateMainActors(int serieId, string newMainActors) = 0;
    virtual void updateMainCharacters(int serieId, string newMainCharacters) = 0;
    virtual void updateNetwork(int serieId, string newNetwork) = 0;
    virtual void updateRating(int serieId, int newRating) = 0;
};

#endif // ABSTRACT_SERIE_DAO_H