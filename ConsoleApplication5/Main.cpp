#include <iostream>
using namespace std;
#include "Date.h"
#include "Facebook.h"
#include "member.h"
#include "Time.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

int menu(Facebook *myFace)
{

	cout << endl << "1. add member \n2. add fan page \n3. add status\n4. show last 10 statuses\n5. add friendship\n6. add fan to page\n7. show all members and pages\n8. show all friends of member\n9. show all fans of page\n10.exit" << endl;

	int choice;
	cin >> choice;
	system("cls");
	if (choice == 1)
	{
		(*myFace).AddMember();
	}
	if (choice == 2)
	{

		(*myFace).AddFanFage();
	}

	if (choice == 3)
	{
		int index1,index;
		member * user;
		fanPage *fan;
		cout << "choose fanPage or members\n1.members\n2.fanpages" << endl;
		cin >> index;
		if (index == 1)
		{
			(*myFace).ShowMembers();
			cout << "Choose the member you would like to post a status from" << endl;

			cin >> index;
			user = (*myFace).GetMember(index);
			user->WritePost();
		}
			
		else
		{
			(*myFace).ShowFanPage();
			cout << "Choose the member you would like to post a status from" << endl;

			cin >> index;
			fan = (*myFace).GetFanPage(index);
			fan->WritePostFanPage();
		}

		

	}

	if (choice == 4)
	{
		int index;
		member * user;
		cout << "Choose the member you would like to post a status from" << endl;
		(*myFace).ShowMembers();
		cin >> index;
		user = (*myFace).GetMember(index);
		user->showLastTenFriendsStatuses();

	}

	if (choice == 5)
	{
		//	cout << endl << "From the below users, choose one that you will add him a friend:" << endl;
		myFace->setfriendship();
	}


	if (choice == 6)
	{
		//	cout << endl << "From the below users, choose one that you will add him a friend:" << endl;
		myFace->LikePage();
	}
	if (choice == 7)
	{
		cout << endl << "Facebook members:" << endl;
		(*myFace).ShowMembers();
		cout << endl << "Facebook pages:" << endl;
		(*myFace).ShowFanPage();
	}



	if (choice == 8)
	{
		member *TheMember;
		int NumOfFriend;
		cout << endl << "choose the member you'd like to check his friends" << endl;
		(*myFace).ShowMembers();
		cin >> NumOfFriend;
		TheMember = (*myFace).GetMember(NumOfFriend);

		(*TheMember).showFriends();
	}
	if (choice == 9)
	{
		int NumOfPage;
		fanPage *page;
		cout << endl << "choose the member you'd like to check his friends" << endl;
		(*myFace).ShowFanPage();
		cin >> NumOfPage;
		page = (*myFace).GetFanPage(NumOfPage);
		(*page).showFollowers();
	}


	return choice;
}

void main()
{
	cout << "WELCOME TO THE NEW GENERATION OF FACEBOOK!!!" << endl << endl;
	Facebook myface;
	int choice;
	choice = menu(&myface);
	while (choice < 10 && choice>0)
	{
		choice = menu(&myface);
	}
}