#include "controller/Controller.h"
#include "utils/SysInfo.h"
#include "utils/Utils.h"

#include <string>
#include <exception>
#include <memory>

using namespace std;

void welcome(void);
void bye(void);

int main(int argc, char *argv[])
{
	welcome();

	try
	{
		Controller controller = Controller();
		controller.start();
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
