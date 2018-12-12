#include "fanPage.h"
#include "member.h"
#include <string.h>
using std::cout;
using std::endl;;

fanPage::fanPage(const fanPage& other)
{
	int i, size = strlen(other.name);
	name = new char[size + 1];

	for (i = 0; i < size; i++)
	{
		name[i] = other.name[i];

	}
	name[i] = '\0';
	//strcpy(name, other.name);	

}



fanPage::fanPage()
{
	this->name = NULL;

}

fanPage::fanPage(char *name)
{
	this->name = name;

}

void fanPage::WritePostFanPage()
{
	status * newstatus = new status[1];
	this->arrayStatus[this->logicSizeOfStatus] = newstatus;
	logicSizeOfStatus++;
	if (logicSizeOfStatus == physicSizeOfStatus)
		AllocateMemoryStatus();
}




void  fanPage::AllocateMemoryStatus()
{

	physicSizeOfStatus *= 2;
	status **tempArry = new status*[physicSizeOfStatus];
	for (int i = 0; i < logicSizeOfStatus; i++)
	{
		tempArry[i] = arrayStatus[i];
	}
	delete[] arrayStatus;
	this->arrayStatus = tempArry;

}

void  fanPage::AllocateMemoryForMembers()
{

	PhysicalNumberOfFollowers *= 2;
	member **tempArry = new member*[PhysicalNumberOfFollowers];
	for (int i = 0; i < LogicalNumberOfFollowers; i++)
	{
		tempArry[i] = ArrOfFollowers[i];
	}
	delete[] ArrOfFollowers;
	this->ArrOfFollowers = tempArry;

}



fanPage::~fanPage()
{
	delete[]name;
	delete[]ArrOfFollowers;
}

char * fanPage::getPageName()
{
	return name;

}
void fanPage::setName(char *name)
{
	this->name = name;
}

void fanPage::showFollowers()
{
	if (this->LogicalNumberOfFollowers == 0)
	{
		cout << this->getPageName() << " has no Facebook followers" << endl;
	}
	else
	{
		cout << this->getPageName() << "'s Facebook's followers are::" << endl;
		for (int i = 0; i < LogicalNumberOfFollowers; i++)
		{
			cout << i << ". " << this->ArrOfFollowers[i]->getName();

		}
	}
}

