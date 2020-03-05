#include "basicTools.h"

void SearchDisk(const std::string& path, std::unordered_set<std::string>& subFiles)
{
	std::string matchFile = path + "\\" + "*.*";
	_finddata_t fileAttr;
	long handle = _findfirst(matchFile.c_str(), &fileAttr);
	if (handle == -1)
	{
		perror("Search failed!");
		std::cout << matchFile << std::endl;
		return;
	}
	do
	{
		if (fileAttr.attrib & _A_SUBDIR)
		{
			if (strcmp(fileAttr.name, ".") != 0 && strcmp(fileAttr.name, "..") != 0)
			{
				SearchDisk(path + "\\" + fileAttr.name, subFiles);
			}
		}
		else
		{
			subFiles.insert(path + "\\" + fileAttr.name);
		}
	} while (_findnext(handle, &fileAttr) == 0);
	_findclose(handle);
}



//É¾³ýÎÄ¼þ
void DeleteFile(const char* fileName)
{
	if (remove(fileName) == 0)
	{
		std::cout << "Delete file :  " << fileName << "  success!" << std::endl;
	}
	else
	{
		perror("Delete file failed!");
	}
}
