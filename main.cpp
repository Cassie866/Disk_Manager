#include "fileManagerTools.h"

void Menu()
{
	std::cout << "*****************************" << std::endl;
	std::cout << "\t1.扫描文件夹"<< std::endl;
	std::cout << "\t2.显示所有文件" << std::endl;
	std::cout << "\t3.显示副本列表" << std::endl;
	std::cout << "\t4.按文件名删除副本" << std::endl;
	std::cout << "\t5.按MD5值删除副本" << std::endl;
	std::cout << "\t6.删除全部副本" << std::endl;
	std::cout << "\t0.退出菜单" << std::endl;
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
		std::cout << "请输入选项：";
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