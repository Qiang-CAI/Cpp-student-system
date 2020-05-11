
#include"loading.h"

void login();
void load();

User client;
User buffer[100];
User *head = buffer;      //头结点

void welcome()
{
	system("cls");
	system("color B1");
	cout << ("         |```````````````````````````````````|") << endl;
	cout << ("         |                                   |") << endl;
	cout << ("         |                                   |") << endl;
	cout << ("         |        欢迎使用学生系统           |") << endl;
	cout << ("         |                                   |") << endl;
	cout << ("         |        0.注册     1.登录          |") << endl;
	cout << ("         |                                   |") << endl;
	cout << ("         |```````````````````````````````````|") << endl;
	int n;
	cout << "请输入：";
	cin >> n;
	switch (n)
	{
	case 0:
		login(); break;
	case 1:
		load(); break;
	default:
		cout << "输入错误，返回主界面！";
		Sleep(1000);
		welcome();
		break;
	}
}
void login()   //注册账号密码并写入TXT文件
{

	User User1;
	cout << "请输入账号（以回车键结束）：";
	cin >> User1.User_ID;
	cout << endl;
	cout << "请输入密码（以回车键结束）：";
	cin >> User1.User_password;
	ofstream input;
	input.open("User.txt", ios::out | ios::app);
	if (!input.is_open())
	{
		cout << "Error Opening file!";
		exit(1);
	}
	else                //写入操作
	{

		input << User1.User_ID << "\n";
		input << User1.User_password << "\n";
	}
	input.close();
	cout << endl;
	cout << "注册成功!正在返回登录界面。" << endl;
	Sleep(2000);
	welcome();
}



void input_client()       //读入输入信息
{
	cout << "请输入您的学生账号（以回车键结束）：";
	cin >> client.User_ID;
	cout << endl;
	cout << "请输入您的密码（以回车键结束）：";
	cin >> client.User_password;
	cout << endl;
}
void input_buffer()
{
	ifstream output;         //将文件内容读入缓冲区
	output.open("User.txt", ios::in);
	if (!output.is_open())
	{
		cout << "Error Opening file!";
		exit(1);
	}
	int i = 0;
	User *q = head;
	while (!output.eof())
	{
		output >> buffer[i].User_ID;
		output >> buffer[i].User_password;
		i++;

		q->next = &buffer[i];
		q = q->next;
		//buffer[i].next = NULL;
	}
	output.close();
}


void load()    //检测输入是否正确
{
	input_client();
	input_buffer();

	while (1)
	{
		User *p = head;
		while (p != NULL)
		{
			if ((p->User_ID == client.User_ID) && (p->User_password == client.User_password))
			{
				cout << "登录成功!正在跳转主界面。";
				Sleep(1000);
				return;
			}
			else
				p = p->next;
		}
		if (NULL == p)
		{
			cout << "账号密码错误，请返回重新输入！" << endl;
			Sleep(1000);
			welcome();
		}
	}
}
