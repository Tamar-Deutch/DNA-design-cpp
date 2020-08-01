
#include "manager.h"
#include "commands.h"
#include "CIL.h"

int main ()
{
	CLI cli;
	Manager m(cli);
	m.run();
	return 0;
}
