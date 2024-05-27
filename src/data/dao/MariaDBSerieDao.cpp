#include "MariaDBSerieDao.h"

const string MariaDBSerieDao::SQL_GET_SERIE_LIST = "SELECT * FROM SERIES";
const string MariaDBSerieDao::SQL_GET_SERIE_LIST_ORDERED_BY = "SELECT * FROM SERIES ORDER BY ?";
const string MariaDBSerieDao::SQL_GET_SERIE_BY_ID = "SELECT * FROM SERIES WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_ADD_SERIE = "INSERT INTO SERIES (series_name, release_year, season, episode_count, main_actors, main_characters, network, rating) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
const string MariaDBSerieDao::SQL_REMOVE_SERIE = "DELETE FROM SERIES WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_UPDATE_NAME = "UPDATE SERIES SET series_name = ? WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_UPDATE_YEAR = "UPDATE SERIES SET release_year = ? WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_UPDATE_SEASON = "UPDATE SERIES SET season = ? WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_UPDATE_EPISODE_COUNT = "UPDATE SERIES SET episode_count = ? WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_UPDATE_MAIN_ACTORS = "UPDATE SERIES SET main_actors = ? WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_UPDATE_MAIN_CHARACTERS = "UPDATE SERIES SET main_characters = ? WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_UPDATE_NETWORK = "UPDATE SERIES SET network = ? WHERE internal_id = ?";
const string MariaDBSerieDao::SQL_UPDATE_RATING = "UPDATE SERIES SET rating = ? WHERE internal_id = ?";

MariaDBSerieDao::MariaDBSerieDao(MariaDBConnection *connection)
{
    this->connection = connection;
}

MariaDBSerieDao::~MariaDBSerieDao()
{
}

vector<Serie *> MariaDBSerieDao::getSerieList() const
{
    vector<Serie *> series;

    try
    {
        unique_ptr<sql::Statement> statement(this->connection->getConnection()->createStatement());
        unique_ptr<sql::ResultSet> resultSet(statement->executeQuery(SQL_GET_SERIE_LIST));

        while (resultSet->next())
        {
            Serie *serie = new Serie(
                resultSet->getInt("internal_id"),
                resultSet->getString("series_name").c_str(),
                resultSet->getInt("release_year"),
                resultSet->getInt("season"),
                resultSet->getInt("episode_count"),
                resultSet->getString("main_actors").c_str(),
                resultSet->getString("main_characters").c_str(),
                resultSet->getString("network").c_str(),
                resultSet->getInt("rating")
            );

            series.push_back(serie);
        }
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error selecting Series: " << e.what() << endl;
    }

    return series;
}

vector<Serie *> MariaDBSerieDao::getSerieListOrderedByTitle() const
{
    vector<Serie *> series;

    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_GET_SERIE_LIST_ORDERED_BY));
        preparedStatement->setString(1, "series_name");
        unique_ptr<sql::ResultSet> resultSet(preparedStatement->executeQuery());

        while (resultSet->next())
        {
            Serie *serie = new Serie(
                resultSet->getInt("internal_id"),
                resultSet->getString("series_name").c_str(),
                resultSet->getInt("release_year"),
                resultSet->getInt("season"),
                resultSet->getInt("episode_count"),
                resultSet->getString("main_actors").c_str(),
                resultSet->getString("main_characters").c_str(),
                resultSet->getString("network").c_str(),
                resultSet->getInt("rating")
            );

            series.push_back(serie);
        }
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error selecting Series: " << e.what() << endl;
    }

    return series;
}

vector<Serie *> MariaDBSerieDao::getSerieListOrderedByNetwork() const
{
    vector<Serie *> series;

    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_GET_SERIE_LIST_ORDERED_BY));
        preparedStatement->setString(1, "network");
        unique_ptr<sql::ResultSet> resultSet(preparedStatement->executeQuery());

        while (resultSet->next())
        {
            Serie *serie = new Serie(
                resultSet->getInt("internal_id"),
                resultSet->getString("series_name").c_str(),
                resultSet->getInt("release_year"),
                resultSet->getInt("season"),
                resultSet->getInt("episode_count"),
                resultSet->getString("main_actors").c_str(),
                resultSet->getString("main_characters").c_str(),
                resultSet->getString("network").c_str(),
                resultSet->getInt("rating")
            );

            series.push_back(serie);
        }
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error selecting Series: " << e.what() << endl;
    }

    return series;
}

vector<Serie *> MariaDBSerieDao::getSerieListOrderedByYear() const
{
    vector<Serie *> series;

    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_GET_SERIE_LIST_ORDERED_BY));
        preparedStatement->setString(1, "release_year");
        unique_ptr<sql::ResultSet> resultSet(preparedStatement->executeQuery());

        while (resultSet->next())
        {
            Serie *serie = new Serie(
                resultSet->getInt("internal_id"),
                resultSet->getString("series_name").c_str(),
                resultSet->getInt("release_year"),
                resultSet->getInt("season"),
                resultSet->getInt("episode_count"),
                resultSet->getString("main_actors").c_str(),
                resultSet->getString("main_characters").c_str(),
                resultSet->getString("network").c_str(),
                resultSet->getInt("rating")
            );

            series.push_back(serie);
        }
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error selecting Series: " << e.what() << endl;
    }

    return series;
}

vector<Serie *> MariaDBSerieDao::getSerieListOrderedByRating() const
{
    vector<Serie *> series;

    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_GET_SERIE_LIST_ORDERED_BY));
        preparedStatement->setString(1, "rating");
        unique_ptr<sql::ResultSet> resultSet(preparedStatement->executeQuery());

        while (resultSet->next())
        {
            Serie *serie = new Serie(
                resultSet->getInt("internal_id"),
                resultSet->getString("series_name").c_str(),
                resultSet->getInt("release_year"),
                resultSet->getInt("season"),
                resultSet->getInt("episode_count"),
                resultSet->getString("main_actors").c_str(),
                resultSet->getString("main_characters").c_str(),
                resultSet->getString("network").c_str(),
                resultSet->getInt("rating")
            );

            series.push_back(serie);
        }
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error selecting Series: " << e.what() << endl;
    }

    return series;
}

Serie *MariaDBSerieDao::getSerieById(int serieId) const
{
    Serie *serie = nullptr;

    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_GET_SERIE_BY_ID));
        preparedStatement->setInt(1, serieId);
        unique_ptr<sql::ResultSet> resultSet(preparedStatement->executeQuery());

        if (resultSet->next())
        {
            serie = new Serie(
                resultSet->getInt("internal_id"),
                resultSet->getString("series_name").c_str(),
                resultSet->getInt("release_year"),
                resultSet->getInt("season"),
                resultSet->getInt("episode_count"),
                resultSet->getString("main_actors").c_str(),
                resultSet->getString("main_characters").c_str(),
                resultSet->getString("network").c_str(),
                resultSet->getInt("rating")
            );
        }
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error selecting Series: " << e.what() << endl;
    }
    
    return serie;
}

void MariaDBSerieDao::addSerie(Serie *serie)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_ADD_SERIE));
        preparedStatement->setString(1, serie->getSerieName());
        preparedStatement->setInt(2, serie->getReleaseYear());
        preparedStatement->setInt(3, serie->getSeason());
        preparedStatement->setInt(4, serie->getEpisodeCount());
        preparedStatement->setString(5, serie->getMainActors());
        preparedStatement->setString(6, serie->getMainCharacters());
        preparedStatement->setString(7, serie->getNetwork());
        preparedStatement->setInt(8, serie->getRating());

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error inserting Serie: " << e.what() << endl;
    }
}

void MariaDBSerieDao::removeSerie(int serieId)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_REMOVE_SERIE));
        preparedStatement->setInt(1, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error deleting Serie: " << e.what() << endl;
    }
}

void MariaDBSerieDao::updateSerieName(int serieId, string newName)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_UPDATE_NAME));
        preparedStatement->setString(1, newName);
        preparedStatement->setInt(2, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error updating Serie name: " << e.what() << endl;
    }
}

void MariaDBSerieDao::updateSerieYear(int serieId, int newYear)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_UPDATE_YEAR));
        preparedStatement->setInt(1, newYear);
        preparedStatement->setInt(2, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error updating Serie release year: " << e.what() << endl;
    }
}

void MariaDBSerieDao::updateSerieSeason(int serieId, int newSeason)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_UPDATE_SEASON));
        preparedStatement->setInt(1, newSeason);
        preparedStatement->setInt(2, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error updating Serie season: " << e.what() << endl;
    }
}

void MariaDBSerieDao::updateSerieEpisodeCount(int serieId, int newEpisodeCount)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_UPDATE_EPISODE_COUNT));
        preparedStatement->setInt(1, newEpisodeCount);
        preparedStatement->setInt(2, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error updating Serie episode count: " << e.what() << endl;
    }
}

void MariaDBSerieDao::updateSerieMainActors(int serieId, string newMainActors)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_UPDATE_MAIN_ACTORS));
        preparedStatement->setString(1, newMainActors);
        preparedStatement->setInt(2, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error updating Serie main actors: " << e.what() << endl;
    }
}

void MariaDBSerieDao::updateSerieMainCharacters(int serieId, string newMainCharacters)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_UPDATE_MAIN_CHARACTERS));
        preparedStatement->setString(1, newMainCharacters);
        preparedStatement->setInt(2, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error updating Serie main characters: " << e.what() << endl;
    }
}

void MariaDBSerieDao::updateSerieNetwork(int serieId, string newNetwork)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_UPDATE_NETWORK));
        preparedStatement->setString(1, newNetwork);
        preparedStatement->setInt(2, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error updating Serie network: " << e.what() << endl;
    }
}

void MariaDBSerieDao::updateSerieRating(int serieId, int newRating)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_UPDATE_RATING));
        preparedStatement->setInt(1, newRating);
        preparedStatement->setInt(2, serieId);

        preparedStatement->execute();
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error updating Serie rating: " << e.what() << endl;
    }
}