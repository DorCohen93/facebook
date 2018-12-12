
#pragma once
#ifndef __FACEBOOK_H
#define __FACEBOOK_H
#include "member.h"
#include "fanPage.h"
// Respect
class member;
class fanPage;

class Facebook
{
public:

	void AddMember();
	void AddFanFage();
	member * GetMember(int index);
	fanPage* GetFanPage(int index);
	void setfriendship();
	void LikePage();
	//GetFanPage;
	void ShowMembers();
	void ShowFanPage();
	~Facebook();
private:
	void  AllocateMemoryFanPage();
	void  AllocateMemoryMembers();
	int LogicalNumberOfMembers = 0;
	int LogicalNumberOfFanPage = 0;
	int PhysicalNumberOfMembers = 1;
	int PhysicalNumberOfFanPage = 1;

	member ** ArryOfMember = new member*[10];
	fanPage ** ArryOfFanPage = new fanPage*[10];


};


#endif
