#pragma once
#ifndef __FANPAGE_H
#define __FANPAGE_H
#include <iostream>
#include "status.h"

class fanPage
{
	friend class member;
private:
	char *name;
	int LogicalNumberOfFollowers = 0;
	int PhysicalNumberOfFollowers = 10;
	int logicSizeOfStatus = 0;
	int physicSizeOfStatus = 1;
	member ** ArrOfFollowers = new member*[10];
	status ** arrayStatus = new status *[10];
	void addFollower(member * follower);
public:
	fanPage();
	fanPage(char * name);
	fanPage(const fanPage& other);
	~fanPage();
	char * getPageName();
	void WritePostFanPage();
	void  AllocateMemoryForMembers();
	void AllocateMemoryStatus();
	void setName(char *name);
	void showFollowers();
};

#endif
