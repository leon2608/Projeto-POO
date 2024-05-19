#include "MariaDBSerieDao.h"

const string MariaDBSerieDao::SQL_GET_ALL_SERIES = "SELECT * FROM series";
const string MariaDBSerieDao::SQL_GET_SERIE_BY_ID = "SELECT * FROM series WHERE id = ?";
const string MariaDBSerieDao::SQL_ADD_SERIE = "INSERT INTO series (name, year, season, episode_count, main_actors, main_characters, network, rating) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
const string MariaDBSerieDao::SQL_REMOVE_SERIE = "DELETE FROM series WHERE id = ?";
const string MariaDBSerieDao::SQL_UPDATE_NAME = "UPDATE series SET name = ? WHERE id = ?";
const string MariaDBSerieDao::SQL_UPDATE_YEAR = "UPDATE series SET year = ? WHERE id = ?";
const string MariaDBSerieDao::SQL_UPDATE_SEASON = "UPDATE series SET season = ? WHERE id = ?";
const string MariaDBSerieDao::SQL_UPDATE_EPISODE_COUNT = "UPDATE series SET episode_count = ? WHERE id = ?";
const string MariaDBSerieDao::SQL_UPDATE_MAIN_ACTORS = "UPDATE series SET main_actors = ? WHERE id = ?";
const string MariaDBSerieDao::SQL_UPDATE_MAIN_CHARACTERS = "UPDATE series SET main_characters = ? WHERE id = ?";
const string MariaDBSerieDao::SQL_UPDATE_NETWORK = "UPDATE series SET network = ? WHERE id = ?";
const string MariaDBSerieDao::SQL_UPDATE_RATING = "UPDATE series SET rating = ? WHERE id = ?";

MariaDBSerieDao::MariaDBSerieDao(MariaDBConnection *connection)
{
    this->connection = connection;
}

MariaDBSerieDao::~MariaDBSerieDao()
{
    delete this->connection;
}

vector<Serie *> MariaDBSerieDao::getSerieList()
{
    vector<Serie *> series;

    try
    {
        unique_ptr<sql::Statement> statement(this->connection->getConnection()->createStatement());
        unique_ptr<sql::ResultSet> resultSet(statement->executeQuery(SQL_GET_ALL_SERIES));

        while (resultSet->next())
        {
            Serie *serie = new Serie(
                resultSet->getInt("id"),
                resultSet->getString("name").c_str(),
                resultSet->getInt("year"),
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

Serie *MariaDBSerieDao::getSerieById(int serieId)
{
    try
    {
        unique_ptr<sql::PreparedStatement> preparedStatement(this->connection->getConnection()->prepareStatement(SQL_GET_SERIE_BY_ID));
        preparedStatement->setInt(1, serieId);
        unique_ptr<sql::ResultSet> resultSet(preparedStatement->executeQuery());

        Serie *serie = nullptr;
        if (resultSet->next())
        {
            serie = new Serie(
                resultSet->getInt("id"),
                resultSet->getString("name").c_str(),
                resultSet->getInt("year"),
                resultSet->getInt("season"),
                resultSet->getInt("episode_count"),
                resultSet->getString("main_actors").c_str(),
                resultSet->getString("main_characters").c_str(),
                resultSet->getString("network").c_str(),
                resultSet->getInt("rating")
            );
        }

        return serie;
    }
    catch(const sql::SQLException &e)
    {
        cerr << "Error selecting Series: " << e.what() << endl;
    }
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
        cerr << "Error updating Serie year: " << e.what() << endl;
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

// TODO: Add class on compilation script (make.sh)
// Path: src/data/dao/MariaDBSerieDao.cpp