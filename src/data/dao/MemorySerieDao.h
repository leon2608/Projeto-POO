#ifndef MEMORY_SERIE_DAO_H
#define MEMORY_SERIE_DAO_H

#include "AbstractSerieDao.h"
#include "../connection/MemoryDBConnection.h"

class MemorySerieDao : public AbstractSerieDao {
private:
    MemoryDBConnection* connection;
    static int lastEntryId;

public:
    MemorySerieDao();
    virtual ~MemorySerieDao();

    virtual vector<Serie*>& getSerieList();
    virtual Serie* getSerieById(int id);
    virtual void add(Serie& serie);
    virtual void update(Serie& serie);
    virtual void remove(Serie& serie);
};

#endif // MEMORY_SERIE_DAO_H