#ifndef ABSTRACT_SERIE_DAO_H
#define ABSTRACT_SERIE_DAO_H

#include <vector>
#include "../../model/Serie.h"

using namespace std;

class AbstractSerieDao {
public:
    AbstractSerieDao() {}
    virtual ~AbstractSerieDao() {}

    virtual vector<Serie*>& getSerieList() = 0;
    virtual Serie* getSerieById(int id) = 0;
    virtual void add(Serie& serie) = 0;
    virtual void update(Serie& serie) = 0;
    virtual void remove(Serie& serie) = 0;
};

#endif // ABSTRACT_SERIE_DAO_H