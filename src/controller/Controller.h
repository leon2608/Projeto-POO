#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>

#include "SerieController.h"
#include "../data/dao/MemorySerieDao.h"
#include "../data/dao/MariaDBSerieDao.h"

using namespace std;

class Controller
{
private:
    MemoryDBConnection *memoryDBConnection;
    MariaDBConnection *mariaDBConnection;
    AbstractSerieDao *serieDao;
    SerieController *serieController;

    void actionSeries();
    void actionReports();
    void actionHelp();
    void actionCredits();

    void launchActions(string title, vector<string>, vector<void (Controller::*)()> functions);

public:
    Controller();
    virtual ~Controller();
    void start();
};

#endif
//  CONTROLLER_H