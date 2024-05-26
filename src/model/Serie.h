#ifndef SERIE_H
#define SERIE_H

#include <iostream>
#include <string>

using namespace std;

class Serie
{
private:
    int internalId;
    string serieName;
    int releaseYear;
    int season;
    int episodeCount;
    string mainActors;
    string mainCharacters;
    string network;
    int rating;

public:
    Serie(int, string, int, int, int, string, string, string, int);
    virtual ~Serie();

    int getInternalId();
    void setSerieId(int serieId);
    string getSerieName();
    int getReleaseYear();
    int getSeason();
    int getEpisodeCount();
    string getMainActors();
    string getMainCharacters();
    string getNetwork();
    int getRating();

    void setSerieName(string name);
    void setReleaseYear(int year);
    void setSeason(int season);
    void setEpisodeCount(int episodeNumber);
    void setMainActors(string mainActors);
    void setMainCharacters(string mainCharacters);
    void setNetwork(string network);
    void setRating(int rating);

    friend ostream& operator<<(std::ostream& os, const Serie& serie);
};

#endif // SERIE_H
