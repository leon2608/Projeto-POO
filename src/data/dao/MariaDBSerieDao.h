#ifndef MARIA_DB_SERIE_DAO_H
#define MARIA_DB_SERIE_DAO_H

#include "AbstractSerieDao.h"
#include "../connection/MariaDBconnection.h"

class MariaDBSerieDao : public AbstractSerieDao
{
private:
    static const string SQL_GET_ALL_SERIES;
    static const string SQL_GET_SERIE_BY_ID;
    static const string SQL_ADD_SERIE;
    static const string SQL_REMOVE_SERIE;
    static const string SQL_UPDATE_NAME;
    static const string SQL_UPDATE_YEAR;
    static const string SQL_UPDATE_SEASON;
    static const string SQL_UPDATE_EPISODE_COUNT;
    static const string SQL_UPDATE_MAIN_ACTORS;
    static const string SQL_UPDATE_MAIN_CHARACTERS;
    static const string SQL_UPDATE_NETWORK;
    static const string SQL_UPDATE_RATING;

    MariaDBConnection *connection;
    //TODO: Evaluate wheter is necessary to keep track of the lastEntryId
    static int lastEntryId;

public:
    MariaDBSerieDao(MariaDBConnection *memoryDBConnection);
    virtual ~MariaDBSerieDao();
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

#endif // MARIA_DB_SERIE_DAO_H