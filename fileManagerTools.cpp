#include "fileManagerTools.h"

void FileManagerTool::ScanDisk()
{
	std::cout << "请输入要扫描的文件夹：";
	std::string path;
	getline(std::cin, path);
	_fm.ScanDisk(path);
}

void FileManagerTool::DeleteByMD5()
{
	std::cout << "请输入要删除文件的MD5值：";
	std::string md5;
	std::cin >> md5;
	_fm.DeleteByMD5(md5);
}

void FileManagerTool::DeleteByName()
{
	std::cout << "请输入要删除的文件名：";
	std::string f;
	getline(std::cin, f);
	_fm.DeleteByName(f);
}

void FileManagerTool::DeleteAllCopy()
{
	_fm.DeleteAllCopy();
}


void FileManagerTool::ShowCopyList()
{
	_fm.ShowCopyList();
}


void FileManagerTool::ShowAllFiles()
{
	_fm.ShowAllFiles();
}