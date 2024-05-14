#ifndef MEMORY_DB_CONNECTION_H
#define MEMORY_DB_CONNECTION_H

#include "../../model/Serie.h"
#include <vector>

using namespace std;

class MemoryDBConnection {
private:
    vector<Serie*> series;
    
public:
    MemoryDBConnection();
    virtual ~MemoryDBConnection();

    vector<Serie*>& getSerieList();
    void close();
};

#endif // MEMORY_DB_CONNECTION_H