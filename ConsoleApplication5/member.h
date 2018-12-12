#pragma once
#ifndef __MEMBER_H
#define __MEMBER_H
#define NOTHINGTOCHECK -1
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "Date.h"
#include "Facebook.h"
#include "status.h"
#include <string.h>



class facebook;
class fanPage;
class member
{

private:
	char *name;
	Date birthday;
	int whereToCheck;
	//Status * memberStatuses;
	int logicSizeOfFriends = 0;
	int physicSizeOfFriends = 4;
	int logicSizeOfStatus = 0;
	int physicSizeOfStatus = 1;
	int logicSizeOfPage = 0;
	int physicSizeOfPage = 4;
	member ** friends = new member *[1];
	fanPage ** pageArr = new fanPage *[1];
	//status ** LastStatus;
	status ** MemberStatus = new status *[1];
	void  AllocateMemoryFriends();
	void  AllocateMemoryStatus();
	void  AllocateMemoryFanPage();
public:


	member() = default;
	void showLastTenFriendsStatuses();

	member(char name[20], Date birthday, member ** friends);
	member(const member& other);
	int setFriends(member *newfriend);
	char * getName()
	{
		return name;

	}

	int LikeFanPage(fanPage *page);
	void getBirthDay()
	{
		this->birthday.ShowDate();

	}
	void setName(char *name);
	void WritePost();
	void setBirthDay(int day, int month, int year);

	void showFriends();
	void showPages();
	void showPosts();
	~member();


};
#endif // __MEMBER_H