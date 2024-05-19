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

public:
    MariaDBSerieDao(MariaDBConnection *memoryDBConnection);
    virtual ~MariaDBSerieDao();

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

#endif // MARIA_DB_SERIE_DAO_H