#pragma once
#include "fileManager.h"
#include <iostream>

class FileManagerTool
{
public:
	void ScanDisk();
	void DeleteByMD5();
	void DeleteByName();
	void DeleteAllCopy();
	void ShowCopyList();
	void ShowAllFiles();
private:
	FileManager _fm;
};