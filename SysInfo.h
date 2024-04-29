/*
 * SysInfo.cpp
 *
 * Created on: April 29, 2024
 *       Author: Leonardo, Vinicius, Luis and Gabriel
 */

#ifndef SYSINFO_H_
#define SYSINFO_H_

using namespace std;

#include <string>

class SysInfo final
{
private:
    static const string author;
    static const string date;
    static const string department;
    static const string institution;
    static const string systemName;
    static const string version;
    static const string helpFile;

public:
    static const string &getAuthor();
    static const string &getDate();
    static const string &getDepartment();
    static const string &getInstitution();
    static const string &getSystemName();
    static const string &getVersion();
    static const string &getHelpFile();

    static const string getFullVersion();
};

#endif /* SYSINFO_H_ */
