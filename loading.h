#pragma once

/*******************************
|   data:       20200506
|   writer:     ��ǿ
|   function��  student_system
|*******************************/

#ifndef LOADING_H
#define LOADING_H
#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>

using namespace std;

struct User         //�û�����
{
	string User_ID;
	string User_password;
	struct User * next;
};
/*
User client;
User buffer[100];
User *head = buffer;      //ͷ���
*/

void login();
void load();
void welcome();




#endif // !LOADING_H
