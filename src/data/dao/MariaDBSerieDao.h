#ifndef MARIA_DB_SERIE_DAO_H
#define MARIA_DB_SERIE_DAO_H

#include "AbstractSerieDao.h"
#include "../connection/MariaDBconnection.h"

class MariaDBSerieDao : public AbstractSerieDao
{
private:
    static const string SQL_GET_SERIE_LIST;
    static const string SQL_GET_SERIE_LIST_ORDERED_BY;
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

#endif // MARIA_DB_SERIE_DAO_H