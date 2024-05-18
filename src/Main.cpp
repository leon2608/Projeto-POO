#include <string>
#include <exception>
#include <memory>

#include "controller/Controller.h"
#include "utils/SysInfo.h"
#include "utils/Utils.h"

using namespace std;

void welcome(void);
void bye(void);

int main(int argc, char *argv[])
{
	welcome();

	try
	{
		(make_unique<Controller>())->start();
	}
	catch (const exception &myException)
	{
		Utils::printMessage("Unexpected problem. Program aborted. " + string(myException.what()));
		exit(1);
	}

	bye();
	return (0);
}

void welcome()
{
	Utils::printMessage(SysInfo::getFullVersion());
	Utils::printMessage("Running now...");
}

void bye()
{
	Utils::printMessage("Finished");
}
