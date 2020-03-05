#include "fileManagerTools.h"

void FileManagerTool::ScanDisk()
{
	std::cout << "������Ҫɨ����ļ��У�";
	std::string path;
	getline(std::cin, path);
	_fm.ScanDisk(path);
}

void FileManagerTool::DeleteByMD5()
{
	std::cout << "������Ҫɾ���ļ���MD5ֵ��";
	std::string md5;
	std::cin >> md5;
	_fm.DeleteByMD5(md5);
}

void FileManagerTool::DeleteByName()
{
	std::cout << "������Ҫɾ�����ļ�����";
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