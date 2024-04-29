/*
 * SysInfo.cpp
 *
 * Created on: April 29, 2024
 *       Author: Leonardo, Vinicius, Luis and Gabriel
 */

#include "SysInfo.h"

const string SysInfo::author = "Grupo X";
const string SysInfo::date = "2024, April";
const string SysInfo::department = "Faculdade de Tecnologia - Limeira/SP";
const string SysInfo::institution = "Universidade Estadual de Campinas (Unicamp)";
const string SysInfo::systemName = "Catálogo de SériesC++";
const string SysInfo::version = "0.01";
const string SysInfo::helpFile = "SériesCatálogo.txt";

const string &SysInfo::getAuthor()
{
    return author;
}

const string &SysInfo::getDate()
{
    return date;
}

const string &SysInfo::getDepartment()
{
    return department;
}

const string &SysInfo::getInstitution()
{
    return institution;
}

const string &SysInfo::getSystemName()
{
    return systemName;
}

const string &SysInfo::getVersion()
{
    return version;
}

const string &SysInfo::getHelpFile()
{
    return helpFile;
}

const string SysInfo::getFullVersion()
{
    return systemName + " | Ver. " + version + " (" + date + ")";
}
