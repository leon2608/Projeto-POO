#include "SysInfo.h"

const string SysInfo::author = "Grupo 06";
const string SysInfo::date = "2024";
const string SysInfo::department = "Faculdade de Tecnologia (FT) - Limeira/SP";
const string SysInfo::institution = "Universidade Estadual de Campinas (Unicamp)";
const string SysInfo::systemName = "Sistema de Gerenciamento de Catálogo de Séries em C++";
const string SysInfo::version = "1.0.0";
const string SysInfo::helpFile = "STVSHelp.txt";

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
