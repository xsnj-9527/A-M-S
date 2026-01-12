#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define MAX 1000
//联系人结构体
struct person {
	string m_Name;
	int m_Sex;//1男 2女
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//通讯录结构体
struct Addressbooks {
	struct person personArray[1000];//通讯录中保存的联系人数组
	int m_Size;//通讯录中当前联系人个数
};
//添加联系人
void AddPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return ;
	}
	else {//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" ;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		int sex = 0;
		cout << "请输入性别（1-男，2-女）：" ;	
		while (true)
		{
			cin >> sex;
		    if (sex == 1 || sex == 2) {
			    abs->personArray[abs->m_Size].m_Sex = sex;
		        break;
		    }
		    else {
			    cout << "输入有误，请重新输入！" << endl;
		    }
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：";
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//联系电话
		string phone;
		cout << "请输入联系电话：";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//地址
		string addr;
		cout << "请输入地址：";
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//更新联系人数量
		abs->m_Size ++;
		cout << "添加联系人成功！" << endl;
		system("pause");
		system("cls");
	}
}
//显示联系人
void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名:" <<" " <<abs->personArray[i].m_Name <<setw(8) ;
			cout << "性别:" << " " <<(abs->personArray[i].m_Sex == 1 ?"男":"女" )<< setw(8);
			cout << "年龄:" <<" "  <<abs->personArray[i].m_Age <<setw(12) ;
			cout << "联系电话:" <<" "  <<abs->personArray[i].m_Phone <<setw(8) ;
			cout << "住址:" << " " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找联系人是否存在
int isExist(Addressbooks* abs,string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}     
	}
	return -1;
}
//删除联系人
void deletePerson(Addressbooks *abs){
	cout << "请输入想要删除的联系人姓名：";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];//数据前移
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(Addressbooks* abs) {
	cout << "请输入想要查找的联系人的姓名:";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if(ret != -1){
		cout << "姓名:" << " " << abs->personArray[ret].m_Name << setw(8);
		cout << "性别:" << " " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << setw(8);
		cout << "年龄:" << " " << abs->personArray[ret].m_Age << setw(12);
		cout << "联系电话:" << " " << abs->personArray[ret].m_Phone << setw(8);
		cout << "住址:" << " " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改子菜单
void modifyMenu() {
	cout << "******** 修改选项 ********" << endl;
	cout << "*****   1.修改姓名   *****" << endl;
	cout << "*****   2.修改性别   *****" << endl;
	cout << "*****   3.修改年龄   *****" << endl;
	cout << "*****   4.修改电话   *****" << endl;
	cout << "*****   5.修改住址   *****" << endl;
	cout << "*****   0.退出通讯录 *****" << endl;
	cout << "**************************" << endl;
}
//修改switch循环
void modifySwitch(Addressbooks *abs,int index) {
    int select = 0;
	modifyMenu();
	cin >> select;
	switch (select) {
		case 1:{
			cout << "请重新输入姓名：";
			string newName;
			cin >> newName;
			abs->personArray[index].m_Name = newName;
			cout << "姓名修改成功！" << endl;
			system("pause");
			system("cls");
			modifyMenu;
		}
			  break;
		case 2: {
			cout << "请重新输入性别（1-男，2-女）：";
			int newSex = 0;
			while (true) {
				cin >> newSex;
				if (newSex == 1 || newSex == 2) {
					abs->personArray[index].m_Sex = newSex;
					cout << "性别修改成功！" << endl;
					break;
				}
				else {
					cout << "输入有误，请重新输入（1-男，2-女）：";
				}	
			}	
			system("pause");
			system("cls");
			modifyMenu;
		}
			  break;
		case 3: {
			cout << "请重新输入年龄：";
			int newAge = 0;
			cin >> newAge;
			abs->personArray[index].m_Age = newAge;
			cout << "年龄修改成功！" << endl;
			system("pause");
			system("cls");
			modifyMenu;
		}
			  break;
		case 4: {
			cout << "请重新输入电话号码：";
			string newPhone;
			cin >> newPhone;
			abs->personArray[index].m_Phone = newPhone;
			cout << "电话号码修改成功！" << endl;
			system("pause");
			system("cls");
			modifyMenu;
		}
			  break;
		case 5: {
			cout << "请重新输入住址：";
			string newAddr;
			cin >> newAddr;
			abs->personArray[index].m_Addr = newAddr;
			cout << "住址修改成功！" << endl;
			system("pause");
			system("cls");
			modifyMenu;
		}
			  break;
		case 0:
			cout << "修改已保存。" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			modifyMenu;
			break;
	}

	modifySwitch(abs, index);
}
//修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入想要修改的联系人姓名：";
	string name;
	cin >> name;
	system("pause");
	system("cls");
	int ret = isExist(abs, name);
	if (ret != -1) {
		modifySwitch(abs, ret);
	}
	else {
		cout << "查无此人" << endl;
	}
}
//清空通讯录
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已经被清空" << endl;
	system("pause");
	system("cls");
}

void showMenu() {
	cout<< "** 欢迎使用通讯录管理系统 **" << endl;
	cout<< "*****   1.添加联系人   *****" << endl;
	cout<< "*****   2.显示联系人   *****" << endl;
	cout<< "*****   3.删除联系人   *****" << endl;
	cout<< "*****   4.查找联系人   *****" << endl;
	cout<< "*****   5.修改联系人   *****" << endl;
	cout<< "*****   6.清空联系人   *****" << endl;
	cout<< "*****   0.退出通讯录   *****" << endl;
	cout<< "****************************" << endl;
}

int main() {
	//创建通讯录
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1://添加联系人
			AddPerson(&abs);
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人		
			/*测试代码
			cout << "请输入想要查找的姓名：";
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1) {
				cout << "查无此人" << endl;
			}else {
				cout << "找到此人" << endl;
			}*/
			deletePerson(&abs);
			break;
		case 4://查找联系人
		{
			findPerson(&abs);
		}
		break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}