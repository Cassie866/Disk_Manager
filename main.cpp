#include "fileManagerTools.h"

void Menu()
{
	std::cout << "*****************************" << std::endl;
	std::cout << "\t1.ɨ���ļ���"<< std::endl;
	std::cout << "\t2.��ʾ�����ļ�" << std::endl;
	std::cout << "\t3.��ʾ�����б�" << std::endl;
	std::cout << "\t4.���ļ���ɾ������" << std::endl;
	std::cout << "\t5.��MD5ֵɾ������" << std::endl;
	std::cout << "\t6.ɾ��ȫ������" << std::endl;
	std::cout << "\t0.�˳��˵�" << std::endl;
	std::cout << "*****************************" << std::endl;
}


void FileManagerFun()
{
	FileManagerTool fmt;
	int input;
	do
	{
		Menu();
		std::string g;
		std::cout << "������ѡ�";
		std::cin >> input;
		getline(std::cin, g);
		switch (input)
		{
		case 1:
			fmt.ScanDisk();
			break;
		case 2:
			fmt.ShowAllFiles();
			break;
		case 3:
			fmt.ShowCopyList();
			break;
		case 4:
			fmt.DeleteByName();
			break;
		case 5:
			fmt.DeleteByMD5();
			break;
		case 6:
			fmt.DeleteAllCopy();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input != 0);
}


int main()
{
	FileManagerFun();
	return 0;
}