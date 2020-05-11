#pragma once

/*******************************
|   data:       20200508
|   writer:     蔡强
|   function：  student_system
|*******************************/

#ifndef _STUDENT_INFO_
#define _STUDENT_INFO_
#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>

using namespace std;

struct student
{

	string name;
	string num;
	char sex ;     //M为男性，W为女性
	string age;
	struct student *next;
	
};
/*
student stubuffer[100];
student  *shead = stubuffer;     //头节点
*/

void menu();
void input_stubuffer();
void save();
void addinfo();
void delinfo();
void changeinfo();
void findinfo();
void show_all();




#endif