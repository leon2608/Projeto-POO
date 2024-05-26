#ifndef SERIE_CONTROLLER_H
#define SERIE_CONTROLLER_H

#include <string>
#include <vector>

#include "../data/dao/MemorySerieDao.h"
#include "../data/dao/MariaDBSerieDao.h"
#include "../utils/Utils.h"

using namespace std;

class SerieController
{
private:
    MemoryDBConnection *memoryDBConnection;
    MariaDBConnection *mariaDBConnection;
    AbstractSerieDao *serieDao;
    Utils *utils;

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

    Serie* addRegister();
};

#endif // SERIE_CONTROLLER_H