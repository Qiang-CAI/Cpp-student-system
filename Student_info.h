#pragma once

/*******************************
|   data:       20200508
|   writer:     ��ǿ
|   function��  student_system
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
	char sex ;     //MΪ���ԣ�WΪŮ��
	string age;
	struct student *next;
	
};
/*
student stubuffer[100];
student  *shead = stubuffer;     //ͷ�ڵ�
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