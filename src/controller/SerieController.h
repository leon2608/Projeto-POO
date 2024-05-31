#ifndef SERIE_CONTROLLER_H
#define SERIE_CONTROLLER_H

#include <string>
#include <vector>

#include "../data/dao/AbstractSerieDao.h"
#include "../data/dao/MariaDBSerieDao.h"
#include "../data/dao/MemorySerieDao.h"
#include "../utils/Utils.h"

using namespace std;

class SerieController
{
private:
    AbstractSerieDao *serieDao;
    MariaDBConnection *mariaDBConnection;
    MemoryDBConnection *memoryDBConnection;
    Utils *utils;

    Serie* addRegister();

    void actionSeriesAddRegister(void);
    void actionSeriesRestoreRegister(void);
    void actionSeriesEditRegister(void);
    void actionSeriesRemoveRegister(void);

    void actionReportsOrderByTitle(void);
    void actionReportsOrderByNetwork(void);
    void actionReportsOrderByYear(void);
    void actionReportsOrderByRating(void);

    void launchActions(string title, vector<string>, vector<void (SerieController::*)()> functions);

public:
    SerieController();
    virtual ~SerieController();
    void launchActionsSeries(void);
    void launchActionsReports(void);
    void launchActionsCredits(void);
};

#endif // SERIE_CONTROLLER_H