
#include"loading.h"

void login();
void load();

User client;
User buffer[100];
User *head = buffer;      //ͷ���

void welcome()
{
	system("cls");
	system("color B1");
	cout << ("         |```````````````````````````````````|") << endl;
	cout << ("         |                                   |") << endl;
	cout << ("         |                                   |") << endl;
	cout << ("         |        ��ӭʹ��ѧ��ϵͳ           |") << endl;
	cout << ("         |                                   |") << endl;
	cout << ("         |        0.ע��     1.��¼          |") << endl;
	cout << ("         |                                   |") << endl;
	cout << ("         |```````````````````````````````````|") << endl;
	int n;
	cout << "�����룺";
	cin >> n;
	switch (n)
	{
	case 0:
		login(); break;
	case 1:
		load(); break;
	default:
		cout << "������󣬷��������棡";
		Sleep(1000);
		welcome();
		break;
	}
}
void login()   //ע���˺����벢д��TXT�ļ�
{

	User User1;
	cout << "�������˺ţ��Իس�����������";
	cin >> User1.User_ID;
	cout << endl;
	cout << "���������루�Իس�����������";
	cin >> User1.User_password;
	ofstream input;
	input.open("User.txt", ios::out | ios::app);
	if (!input.is_open())
	{
		cout << "Error Opening file!";
		exit(1);
	}
	else                //д�����
	{

		input << User1.User_ID << "\n";
		input << User1.User_password << "\n";
	}
	input.close();
	cout << endl;
	cout << "ע��ɹ�!���ڷ��ص�¼���档" << endl;
	Sleep(2000);
	welcome();
}



void input_client()       //����������Ϣ
{
	cout << "����������ѧ���˺ţ��Իس�����������";
	cin >> client.User_ID;
	cout << endl;
	cout << "�������������루�Իس�����������";
	cin >> client.User_password;
	cout << endl;
}
void input_buffer()
{
	ifstream output;         //���ļ����ݶ��뻺����
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


void load()    //��������Ƿ���ȷ
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
				cout << "��¼�ɹ�!������ת�����档";
				Sleep(1000);
				return;
			}
			else
				p = p->next;
		}
		if (NULL == p)
		{
			cout << "�˺���������뷵���������룡" << endl;
			Sleep(1000);
			welcome();
		}
	}
}
