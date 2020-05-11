
#include"Student_info.h"


student stubuffer[100];
student  *shead = stubuffer;     //头节点

void input_stubuffer()            //将文件内容读入缓存
{
	ifstream output("student.txt", ios::in);
	if (!output.is_open())
	{
		cout << "Error Opening file.";
		exit(1);
	}
	int i = 0;
	student *temp = shead;
	output.seekg(0, ios::end);        //设置偏移量计算文件初始是否为空  end:文件尾
	streampos fp = output.tellg();
	if (int(fp) == 0)
	{
		output.close();
		return;
	}
	else
	{
		output.seekg(0, ios::beg);    //beg:将指针置头
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
void save()                        //将缓冲区内容保存至文件
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
	cout << "请输入姓名（以回车键结束）：";
	cin >> stubuffer[i].name;
	cout << "请输入学号（以回车键结束）：";
	cin >> stubuffer[i].num;
	cout << "请输入性别（M：男性，W：女性）：";
	cin >> stubuffer[i].sex;
	cout << "请输入年龄（以回车键结束）：";
	cin >> stubuffer[i].age;
	cout << "添加成功，正在返回主菜单。";
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
	cout << "请输入你想删除的学生姓名：";
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
			cout << "删除成功，正在返回主菜单";
			break;
						
		}
		else
		{
			p = p->next;
		}
	}
	if (NULL == p)
	{
		cout << "错误！未查找到该学生，请返回主菜单重新输入";
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
	cout << "请输入你想修改的原始学生姓名：";
	cin >> change_stud.name;
	while (NULL != p)
	{
		if (p->name == change_stud.name)
		{
			cout << "请输入修改后的姓名：";
			cin >> change_stud.name;
			p->name = change_stud.name;
			cout << "请输入修改后的学号：";
			cin >> change_stud.num;
			p->num = change_stud.num;
			cout << "请输入修改后的性别：";
			cin >> change_stud.sex;
			p->sex = change_stud.sex;
			cout << "请输入修改后的年龄：";
			cin >> change_stud.age;
			p->age = change_stud.age;
			cout << "修改成功，正在返回主菜单！";
			break;
		}
		else
		{
			p = p->next;
		}
	}
	if (NULL == p)
	{
		cout << "错误！未查找到该学生，请返回主菜单重新输入";
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
	cout << "请输入查找学号";
	cin >> find_stud.num;
	while (NULL != p)
	{
		if (p->num == find_stud.num)
		{
			cout << "查找成功，学生信息如下：" << endl;
			cout << "姓名：" << p->name << endl;
			cout << "学号：" << p->num << endl;
			cout << "性别：" << p->sex << endl;
			cout << "年龄：" << p->age << endl;
			break;
		}
		else
		{
			p = p->next;
		}
	}
	if (NULL == p)
	{
		cout << "错误！未查找到该学生，请返回主菜单重新输入";
		menu();
	}
	int n;
	cout << "是否继续查找（0：返回主菜单  1：继续查找）:";
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
	cout << "全部学生信息如下：" << endl;
	while (NULL != p->next)
	{
		cout << "姓名：" << p->name << endl;
		cout << "学号：" << p->num << endl;
		cout << "性别：" << p->sex << endl;
		cout << "年龄：" << p->age << endl;
		p = p->next;
	}
	int n;
	cout << "返回主菜单请按1：";
	cin >> n;
	while (1)
	{
		if (1 == n)
		{
			menu();
		}
		cout << "输入错误，请重新输入：";
		cin >> n;
	}
}



void menu()
{
	system("cls");
	system("color E4");
	cout << ("    |________________________________________________|") << endl;
	cout << ("    |                                                |") << endl;
	cout << ("    |                学生信息管理系统                |") << endl;
	cout << ("    |                                                |") << endl;
	cout << ("    |               0、退出系统                      |") << endl;
	cout << ("    |               1、增加学生信息                  |") << endl;
	cout << ("    |               2、删除学生信息                  |") << endl;
	cout << ("    |               3、修改学生信息                  |") << endl;
	cout << ("    |               4、查找学生的信息                |") << endl;
	cout << ("    |               5、浏览全部学生信息              |") << endl;
	cout << ("    |                                                |") << endl;
	cout << ("    |________________________________________________|") << endl;

	int n;
	cout << "请输入：";
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
