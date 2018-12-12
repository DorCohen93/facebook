#pragma once
#ifndef __STATUS_H
#define __STATUS_H
#include <ctime>
#include "Date.h"
#include "Time.h"

enum KIND { text, photo, video };
class status
{
	friend class member;

private:
	char * post;
	Date postDate;
	Time postTime;
	KIND kind;
	//		Time postTime;


public:
	status();
	status(const status&other);
	int compare(status *statusToCheck);
	void show();
	char *GetTheStatus();
	Date GetStatusDate();
	~status();
};
#endif
