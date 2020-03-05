#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include  "MD5.h"

class FileManager
{
public:
	void ScanDisk(const std::string& path);
	void GetCopyList();

	void DeleteByName(const std::string& name);
	void DeleteByMD5(const std::string& md5);
	void DeleteByMD52(const std::string& md5);
	void DeleteAllCopy();

	void ShowCopyList();
	void ShowAllFiles();

private:
	std::unordered_set<std::string> _files;   //���������ļ�
	std::unordered_multimap<std::string, std::string>_md5toFiles;    //MD5���ļ���ֻ�����и������ļ���
	std::unordered_map<std::string, std::string>_filetoMd5;    //�ļ���MD5����ֻ�����и������ļ���
	MD5 _md5;
};