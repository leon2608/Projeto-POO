#ifndef CONTROLLER_H
#define CONTROLLER_H

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

#endif // CONTROLLER_H