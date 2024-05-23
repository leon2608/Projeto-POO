#include <iostream>
#include <string>
#include <vector>

#include "../model/Serie.h"
#include "../data/dao/MemorySerieDao.h"
#include "../data/dao/AbstractSerieDao.h"
#include "SerieController.h"
#include "../utils/Menu.h"
#include "../utils/Utils.h"

SerieController::SerieController(MemoryDBConnection *memoryDBConnection, MariaDBConnection *mariaDBConnection, AbstractSerieDao *serieDao)
{
    this->memoryDBConnection = memoryDBConnection;
    this->mariaDBConnection = mariaDBConnection;
    this->serieDao = serieDao;
}

SerieController::~SerieController()
{
}

void SerieController::launchActionsSeries(void)
{
}

void SerieController::launchActionsReports(void)
{
}

void SerieController::actionSeriesAddRegister()
{
}

void SerieController::actionSeriesRestoreRegister()
{
}

void SerieController::actionSeriesEditRegister()
{
}

void SerieController::actionSeriesRemoveRegister()
{
}

void SerieController::actionReportsOrderByTitle(void)
{
}

void SerieController::actionReportsOrderByNetwork(void)
{
}

void SerieController::actionReportsOrderByYear(void)
{
}

void SerieController::actionReportsOrderByRating(void)
{
}

void SerieController::launchActions(string title, vector<string>, vector<void (SerieController::*)()> functions)
{
}

