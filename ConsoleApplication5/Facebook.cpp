#include "Facebook.h"

void Facebook::ShowMembers()
{
	for (int i = 0; i < LogicalNumberOfMembers; i++)
	{
		cout << i << " . " << (*ArryOfMember[i]).getName() << endl;
	}

}



void  Facebook::AllocateMemoryMembers()
{

	PhysicalNumberOfMembers *= 2;
	member** tempemoryArr = new member*[PhysicalNumberOfMembers];
	for (int i = 0; i < LogicalNumberOfMembers; i++)
	{
		tempemoryArr[i] = this->ArryOfMember[i];
	}
	delete[] ArryOfMember;
	this->ArryOfMember = tempemoryArr;
}



void  Facebook::AllocateMemoryFanPage()
{

	PhysicalNumberOfFanPage *= 2;
	fanPage** tempemoryArr = new fanPage*[PhysicalNumberOfMembers];
	for (int i = 0; i < LogicalNumberOfFanPage; i++)
	{
		tempemoryArr[i] = this->ArryOfFanPage[i];
	}
	delete[] ArryOfFanPage;
	this->ArryOfFanPage = tempemoryArr;
}


void LikePage(Facebook *myFace)
{
	member *user;
	fanPage *page;
	int userindex, pageindex, flag;

	cout << endl << "From the below users, choose the number of the friend you want to add a page to" << endl;
	(*myFace).ShowMembers();
	cin >> userindex;
	user = (*myFace).GetMember(userindex);

	cout << "now, from the list below choose a page " << endl;
	(*myFace).ShowFanPage();
	cin >> pageindex;
	page = (*myFace).GetFanPage(pageindex);

	flag = user->LikeFanPage(page);
	if (flag == 1)
	{
		cout << user->getName() << " now like the page " << page->getPageName();


	}
	if (flag == 0)
	{
		cout << user->getName() << "already likes this page" << endl;
	}
}


void Facebook::ShowFanPage()
{
	cout << "below you can see all the pages Facebook currently have" << endl;
	for (int i = 0; i < LogicalNumberOfFanPage; i++)
	{
		cout << i << " . " << ArryOfFanPage[i]->getPageName() << endl;
	}

}




void Facebook::LikePage()
{
	member *user;
	fanPage *page;
	int userindex, pageindex, flag;

	cout << endl << "From the below users, choose the number of the friend you want to add a page to" << endl;
	this->ShowMembers();
	cin >> userindex;
	user = this->GetMember(userindex);

	cout << "now, from the list below choose a page " << endl;
	this->ShowFanPage();
	cin >> pageindex;
	page = this->GetFanPage(pageindex);

	flag = user->LikeFanPage(page);
	if (flag == 1)
	{
		cout << user->getName() << " now like the page " << page->getPageName();


	}
	if (flag == 0)
	{
		cout << user->getName() << "already likes this page" << endl;
	}
}


void Facebook::setfriendship()
{
	member *first, *second;
	int firstindex, secondindex, decision, flag;

	cout << endl << "From the below users, choose the numbers of the two you want to set as friends " << endl;
	this->ShowMembers();
	cin >> firstindex >> secondindex;
	first = this->GetMember(firstindex);
	second = this->GetMember(secondindex);
	cout << "Please confirm you would like to set " << first->getName() << " and " << second->getName() << "as friends" << endl;
	cout << "Press 0 to abort, anything else to confirm" << endl;
	cin >> decision;
	if (decision != 0)
		flag = first->setFriends(second);
	if (flag == 0)
	{
		cout << first->getName() << " and " << second->getName() << " are already friends ";
	}
	if (flag == 1)

	{
		cout << first->getName() << " and " << second->getName() << " are now friends " << endl;
	}
}



member *Facebook::GetMember(int index)
{

	return (ArryOfMember[index]);

}

fanPage *Facebook::GetFanPage(int index)
{

	return (ArryOfFanPage[index]);

}

void Facebook::AddMember()
{
	cout << "please enter name and birthday" << endl;
	char *name = new char[20];
	int d, m, y;
	cin >> name;
	cin >> d >> m >> y;
	while (d < 0 || d>30 || m > 12 || m < 0 || y>2018 || y < 1900)
	{
		cout << "please put the correct date\n";
		cin >> d >> m >> y;
	}
	Date birth(d, m, y);


	member(*NewMember) = new member();
	(*NewMember).setName(name);
	(*NewMember).setBirthDay(d, y, m);

	if (name != NULL && NewMember != NULL)
		cout << "user was added successfully :)" << endl;

	ArryOfMember[LogicalNumberOfMembers] = NewMember;
	(this->LogicalNumberOfMembers)++;
	if (LogicalNumberOfMembers == PhysicalNumberOfMembers)
		AllocateMemoryMembers();

}



void Facebook::AddFanFage()
{
	fanPage *NewFanPage;

	cout << "please enter the page's name - 20 letters maximum" << endl;
	char *name = new char[20];

	cin >> name;

	NewFanPage = new fanPage();
	(*NewFanPage).setName(name);


	if (name != NULL && NewFanPage != NULL)
		cout << "fanpage was added successfully :)" << endl;

	ArryOfFanPage[LogicalNumberOfFanPage] = NewFanPage;
	(this->LogicalNumberOfFanPage)++;
	if (LogicalNumberOfFanPage == PhysicalNumberOfFanPage)
		AllocateMemoryFanPage();


}
Facebook::~Facebook()
{
	

	member ** ArryOfMember = new member*[10];
	fanPage ** ArryOfFanPage = new fanPage*[10];
	for (int i = 0; i < LogicalNumberOfMembers; i++)
	{
		delete[]ArryOfMember[i];
	}
	for (int i = 0; i < LogicalNumberOfFanPage; i++)
	{
		delete[]ArryOfFanPage[i];
	}
	delete[]ArryOfFanPage;
	delete[]ArryOfMember;


}
/*
NewMember = new member[1];
Date birthday;
char *name = NULL;
int year = 0, month = 0, day = 0;
while (name == NULL)
{
cout << "Please enter your name" << endl;
cin >> name;
}

while (1900 > year || year > 2018 || 1 > month || month > 12 || 1 > day || day > 30)
{
cout << "Please enter the year you were born, month and day - exactly by this order" << endl;
cin >> year;
cin >> month;
cin >> day;
}

NewMember(name, birthday);
*/