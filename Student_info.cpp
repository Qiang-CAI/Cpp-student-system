
#include"Student_info.h"


student stubuffer[100];
student  *shead = stubuffer;     //ͷ�ڵ�

void input_stubuffer()            //���ļ����ݶ��뻺��
{
	ifstream output("student.txt", ios::in);
	if (!output.is_open())
	{
		cout << "Error Opening file.";
		exit(1);
	}
	int i = 0;
	student *temp = shead;
	output.seekg(0, ios::end);        //����ƫ���������ļ���ʼ�Ƿ�Ϊ��  end:�ļ�β
	streampos fp = output.tellg();
	if (int(fp) == 0)
	{
		output.close();
		return;
	}
	else
	{
		output.seekg(0, ios::beg);    //beg:��ָ����ͷ
		while (!output.eof())
		{
			output >> stubuffer[i].name;
			output >> stubuffer[i].num;
			output >> stubuffer[i].sex;
			output >> stubuffer[i].age;
			i++;
			temp->next = &stubuffer[i];
			temp = temp->next;

		}
		output.close();
	}

}
void save()                        //�����������ݱ������ļ�
{
	student *temp = shead;
	int i = 0;
	ofstream input_file("student.txt", ios::out);
	if (!input_file.is_open())
	{
		cout << "Error Opening File!";
		exit(1);
	}

	while (NULL != temp)
	{
		input_file << stubuffer[i].name << "\n";
		input_file << stubuffer[i].num << "\n";
		input_file << stubuffer[i].sex << "\n";
		input_file << stubuffer[i].age << "\n";
		i++;
		//temp->next = &stubuffer[i];
		temp = temp->next;
	}

	input_file.close();
}

void addinfo()
{
	input_stubuffer();
	student *p = shead;
	int i = 0;
	while (NULL != p->next)
	{
		p = p->next;
		i++;

	}
	system("cls");
	cout << "�������������Իس�����������";
	cin >> stubuffer[i].name;
	cout << "������ѧ�ţ��Իس�����������";
	cin >> stubuffer[i].num;
	cout << "�������Ա�M�����ԣ�W��Ů�ԣ���";
	cin >> stubuffer[i].sex;
	cout << "���������䣨�Իس�����������";
	cin >> stubuffer[i].age;
	cout << "��ӳɹ������ڷ������˵���";
	Sleep(1000);
	save();
	menu();
}
void delinfo()
{
	input_stubuffer();
	system("cls");
	student *p = shead;
	student del_stud;
	cout << "����������ɾ����ѧ��������";
	cin >> del_stud.name;
	while (NULL != p)
	{
		if (p->name == del_stud.name)
		{
			p->name = p->next->name;
			p->num = p->next->num;
			p->sex = p->next->sex;
			p->age = p->next->age;
			p->next = p->next->next;
			cout << "ɾ���ɹ������ڷ������˵�";
			break;
						
		}
		else
		{
			p = p->next;
		}
	}
	if (NULL == p)
	{
		cout << "����δ���ҵ���ѧ�����뷵�����˵���������";
		menu();
	}

	Sleep(1000);
	save();
	menu();
}
void changeinfo()
{
	input_stubuffer();
	system("cls");
	student *p = shead;
	student change_stud;
	cout << "�����������޸ĵ�ԭʼѧ��������";
	cin >> change_stud.name;
	while (NULL != p)
	{
		if (p->name == change_stud.name)
		{
			cout << "�������޸ĺ��������";
			cin >> change_stud.name;
			p->name = change_stud.name;
			cout << "�������޸ĺ��ѧ�ţ�";
			cin >> change_stud.num;
			p->num = change_stud.num;
			cout << "�������޸ĺ���Ա�";
			cin >> change_stud.sex;
			p->sex = change_stud.sex;
			cout << "�������޸ĺ�����䣺";
			cin >> change_stud.age;
			p->age = change_stud.age;
			cout << "�޸ĳɹ������ڷ������˵���";
			break;
		}
		else
		{
			p = p->next;
		}
	}
	if (NULL == p)
	{
		cout << "����δ���ҵ���ѧ�����뷵�����˵���������";
		menu();
	}

	Sleep(1000);
	save();
	menu();
}
void findinfo()
{
	input_stubuffer();
	system("cls");
	student *p = shead;
	student find_stud;
	cout << "���������ѧ��";
	cin >> find_stud.num;
	while (NULL != p)
	{
		if (p->num == find_stud.num)
		{
			cout << "���ҳɹ���ѧ����Ϣ���£�" << endl;
			cout << "������" << p->name << endl;
			cout << "ѧ�ţ�" << p->num << endl;
			cout << "�Ա�" << p->sex << endl;
			cout << "���䣺" << p->age << endl;
			break;
		}
		else
		{
			p = p->next;
		}
	}
	if (NULL == p)
	{
		cout << "����δ���ҵ���ѧ�����뷵�����˵���������";
		menu();
	}
	int n;
	cout << "�Ƿ�������ң�0���������˵�  1���������ң�:";
	cin >> n;
	switch (n)
	{
	case 0:
		menu(); break;
	case 1:
		findinfo(); break;
	default:
		break;
	}
}
void sortinfo()
{
	input_stubuffer();

}
void show_all()
{
	input_stubuffer();
	system("cls");
	student *p = shead;
	cout << "ȫ��ѧ����Ϣ���£�" << endl;
	while (NULL != p->next)
	{
		cout << "������" << p->name << endl;
		cout << "ѧ�ţ�" << p->num << endl;
		cout << "�Ա�" << p->sex << endl;
		cout << "���䣺" << p->age << endl;
		p = p->next;
	}
	int n;
	cout << "�������˵��밴1��";
	cin >> n;
	while (1)
	{
		if (1 == n)
		{
			menu();
		}
		cout << "����������������룺";
		cin >> n;
	}
}



void menu()
{
	system("cls");
	system("color E4");
	cout << ("    |________________________________________________|") << endl;
	cout << ("    |                                                |") << endl;
	cout << ("    |                ѧ����Ϣ����ϵͳ                |") << endl;
	cout << ("    |                                                |") << endl;
	cout << ("    |               0���˳�ϵͳ                      |") << endl;
	cout << ("    |               1������ѧ����Ϣ                  |") << endl;
	cout << ("    |               2��ɾ��ѧ����Ϣ                  |") << endl;
	cout << ("    |               3���޸�ѧ����Ϣ                  |") << endl;
	cout << ("    |               4������ѧ������Ϣ                |") << endl;
	cout << ("    |               5�����ȫ��ѧ����Ϣ              |") << endl;
	cout << ("    |                                                |") << endl;
	cout << ("    |________________________________________________|") << endl;

	int n;
	cout << "�����룺";
	cin >> n;
	switch (n)
	{
	case 0:
		exit(0); break;
	case 1:
		addinfo(); break;
	case 2:
		delinfo(); break;
	case 3:
		changeinfo(); break;
	case 4:
		findinfo(); break;
	case 5:
		show_all(); break;
	default:
		break;
	}
}
