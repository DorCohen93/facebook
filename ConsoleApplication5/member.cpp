
#include "member.h"
#include "Time.h"




void  member::AllocateMemoryFriends()
{

	physicSizeOfFriends *= 2;
	member** tempArry = new member*[physicSizeOfFriends];
	for (int i = 0; i < logicSizeOfFriends; i++)
	{
		tempArry[i] = friends[i];
	}
	delete[] friends;
	this->friends = tempArry;

}




void  member::AllocateMemoryStatus()
{

	physicSizeOfStatus *= 2;
	status ** tempArry = new status*[physicSizeOfStatus];
	for (int i = 0; i < physicSizeOfStatus; i++)
	{
		tempArry[i] = MemberStatus[i];
	}
	delete[] MemberStatus;
	this->MemberStatus = tempArry;

}



void  member::AllocateMemoryFanPage()
{

	physicSizeOfPage *= 2;
	status ** tempArry = new status*[physicSizeOfPage];
	for (int i = 0; i < logicSizeOfPage; i++)
	{
		tempArry[i] = MemberStatus[i];
	}
	delete[] MemberStatus;
	this->MemberStatus = tempArry;

}



void member::showLastTenFriendsStatuses()
{
	char *name;
	int flag = 1;
	status *mostRecentStatus = nullptr, *currStatus;
	member *theWriterOfMostRecentStatus = nullptr;
	for (int i = 0; i < logicSizeOfFriends; i++)
	{
		if (friends[i]->logicSizeOfStatus != 0)
			friends[i]->whereToCheck = friends[i]->logicSizeOfStatus;
		else
			friends[i]->whereToCheck = NOTHINGTOCHECK;
	}
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < logicSizeOfFriends; j++)
		{
			if (friends[j]->whereToCheck != NOTHINGTOCHECK)
			{
				currStatus = friends[j]->MemberStatus[friends[j]->whereToCheck - 1];
				if (mostRecentStatus == nullptr)
				{
					mostRecentStatus = currStatus;
					theWriterOfMostRecentStatus = friends[j];
				}
				else if (mostRecentStatus != nullptr)
				{
					flag = mostRecentStatus->compare(currStatus);

					//flag = checkIfMoreRecent(mostRecentStatus, currStatus);//checking function
					if (flag)
					{
						mostRecentStatus = currStatus;
						theWriterOfMostRecentStatus = friends[j];
					}

				}

			}
		}
		if (mostRecentStatus != nullptr)
		{
			name = theWriterOfMostRecentStatus->getName();
			cout << name << "'s post" << endl;
			mostRecentStatus->show();
		}

		if (theWriterOfMostRecentStatus->whereToCheck <= 1)
			theWriterOfMostRecentStatus->whereToCheck = NOTHINGTOCHECK;
		else
			theWriterOfMostRecentStatus->whereToCheck--;
		mostRecentStatus = nullptr;


	}
}



member::member(char *name, Date birthday, member ** friends)
{
	this->name = name;
	this->birthday = birthday;
}
void member::setName(char *name)
{
	this->name = name;
}
void member::setBirthDay(int day, int month, int year)
{
	birthday.setDay(day);
	birthday.setMonth(month);
	birthday.setYear(year);
}
member::member(const member& other)
{
	int i, size = strlen(other.name);
	name = new char[size + 1];

	for (i = 0; i < size; i++)
	{
		name[i] = other.name[i];

	}
	name[i] = '\0';
	//strcpy(name, other.name);	
	this->birthday = other.birthday;
}


void member::WritePost()
{
	status * newstatus = new status[1];
	this->MemberStatus[this->logicSizeOfStatus] = newstatus;
	logicSizeOfStatus++;
	if (logicSizeOfStatus == physicSizeOfStatus)
		AllocateMemoryStatus();




	/*
	status *post;
	post = new status[1];
	char *words = new char[20];
	Time PostTime;
	Date PostDate;

	time_t rawtime;
	tm timeinfo;
	time(&rawtime);
	errno_t result = localtime_s(&timeinfo, &rawtime);


	PostTime.hours = timeinfo.tm_hour;
	PostTime.minutes = timeinfo.tm_min;
	post->postTime = PostTime;
	PostDate.setDay(timeinfo.tm_mday);
	PostDate.setMonth(timeinfo.tm_mon);
	PostDate.setYear(timeinfo.tm_year + 1900);
	post->postDate = PostDate;
	system("cls");
	cout << "please enter the kind of status\n1.text\n2.photo\n3.video\n";
	int x;
	cin >> x;
	post->kind = (KIND)x;

	cout << endl << "what's on your mind?" << endl;
	/////////////////////////
	cin >> words;
	post->post = words;
	this->MemberStatus[this->logicSizeOfStatus] = post;
	logicSizeOfStatus++;
	if (logicSizeOfStatus == physicSizeOfStatus)
	AllocateMemoryStatus();
	*/
}


int member::setFriends(member *newfriend)
{
	int flag = 1, logicalsize;;
	for (int i = 0; i < this->logicSizeOfFriends; i++)
	{
		if (this->friends[i] == newfriend)
			flag = 0;
	}
	if (flag == 0)
		return 0;


	logicalsize = newfriend->logicSizeOfFriends;
	newfriend->friends[logicalsize] = this;
	this->friends[this->logicSizeOfFriends] = newfriend;
	///////
	logicSizeOfFriends++;
	newfriend->logicSizeOfFriends = newfriend->logicSizeOfFriends + 1;
	if (logicSizeOfFriends == physicSizeOfFriends)
		AllocateMemoryFriends();
	if (newfriend->logicSizeOfFriends == newfriend->physicSizeOfFriends)
		newfriend->AllocateMemoryStatus();
	//////////////////////////////need to increase the size if needed///////////////////////////////////

	return 1;
}


int member::LikeFanPage(fanPage *page)
{
	int flag = 1, logicalsizeofpage;


	for (int i = 0; i < this->logicSizeOfPage; i++)
	{
		if (this->pageArr[i] == page)
			flag = 0;
	}
	if (flag == 0)
		return 0;



	this->pageArr[logicSizeOfPage] = page;
	logicalsizeofpage = this->pageArr[logicSizeOfPage]->LogicalNumberOfFollowers;
	this->pageArr[logicSizeOfPage]->ArrOfFollowers[logicalsizeofpage] = this;
	logicalsizeofpage++;
	logicSizeOfPage++;
	if (logicSizeOfPage == physicSizeOfPage) //increase memory of page for followers
		this->AllocateMemoryFanPage();
	///////
	this->pageArr[logicSizeOfPage]->LogicalNumberOfFollowers = logicalsizeofpage;
	if (logicalsizeofpage == this->pageArr[logicSizeOfPage]->PhysicalNumberOfFollowers) //increase memory of page for followers
		//this->pageArr[logicSizeOfPage]->AllocateMemoryForMembers();
																						//////////////////////////////need to increase the size if needed///////////////////////////////////

		return 1;

}


void member::showFriends()
{
	if (logicSizeOfFriends == 0)
	{

		cout << this->getName() << " has no Facebook friends" << endl;
	}
	else
	{
		cout << this->getName() << "'s Facebook's friends are:" << endl;
		for (int i = 0; i < logicSizeOfFriends; i++)
		{
			cout << i << ". " << friends[i]->name << endl;
		}
	}
}


void member::showPages()
{
	if (logicSizeOfPage == 0)
	{
		cout << this->getName() << " doesn't like any page" << endl;
	}
	else
	{
		cout << this->getName() << " is following the page:" << endl;
		for (int i = 0; i < logicSizeOfFriends; i++)
		{
			cout << i << ". ";
			pageArr[i]->getPageName();
			cout << endl;
		}
	}
}



void member::showPosts()
{
	system("cls");
	char a;
	Date date;
	if (logicSizeOfStatus == 0)
	{

		cout << this->getName() << " doesn't have any posts" << endl;
	}
	else
	{
		cout << this->getName() << "'s posts:" << endl;
		for (int i = 0; i < logicSizeOfStatus; i++)
		{
			cout << i << ". ";
			cout << this->MemberStatus[i]->GetTheStatus();
			date = this->MemberStatus[i]->GetStatusDate();
			cout << "   posted on";
			date.ShowDate();
			cout << endl;
		}
	}

	cout << endl << endl << endl << "press any key to go to the main screen";
	cin >> a;
	system("cls");
}


member::~member()
{
	delete[] name;
	delete[] friends;
	delete[] pageArr;
}
