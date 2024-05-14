#include "MemoryDBConnection.h"

using namespace std;

MemoryDBConnection::MemoryDBConnection() {
    this->series = vector<Serie*>();
}

MemoryDBConnection::~MemoryDBConnection() {
    this->close();
}

vector<Serie*>& MemoryDBConnection::getSerieList() {
    return this->series;
}

void MemoryDBConnection::close() {
    for (Serie* serie : this->series) {
        delete serie;
    }
    this->series.clear();
}