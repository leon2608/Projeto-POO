/*
 * Menu.cpp
 *
 * Created on: April 29, 2024
 *       Author: Leonardo, Vinicius, Luis and Gabriel
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>
#include <vector>

using namespace std;

class Controller
{
private:
    void actionSelect(void);

    void launchActions(string title, vector<string>, vector<void (Controller::*)()> functions);

public:
    virtual ~Controller();
    void start();
};

#endif /* CONTROLLER_H_ */