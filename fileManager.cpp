#include "basicTools.h"
#include "fileManager.h"


void FileManager::ScanDisk(const std::string& path)
{
	_files.clear();
	SearchDisk(path, _files);
	std::cout << "All files :" << std::endl;
	ShowAllFiles();
	GetCopyList();
}


void FileManager::GetCopyList()
{
	_md5toFiles.clear();
	_filetoMd5.clear();
	for (const auto& f : _files)
	{
		_md5.Reset();
		_md5toFiles.insert(make_pair(_md5.GetFileMD5(f.c_str()), f));
	}
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		if (_md5toFiles.count(it->first) > 1)
		{
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.first;
			while (begin != pairIt.second)
			{
				_filetoMd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			it = pairIt.second;
		}
		else
		{
			it = _md5toFiles.erase(it);
		}
	}
}


void FileManager::DeleteByName(const std::string& name)
{
	if (_filetoMd5.count(name) == 0)
	{
		std::cout << name << "\tNot exist!" << std::endl;
		return;
	}
	std::string curMD5 = _filetoMd5[name];
	std::cout << name << "共有 " << _md5toFiles.count(curMD5) << " 个文件" << std::endl;
	auto pairIt = _md5toFiles.equal_range(curMD5);
	auto curIt = pairIt.first;
	int count = 0;
	while (curIt != pairIt.second)
	{
		if (curIt->second != name)
		{
			_files.erase(curIt->second);  //在_file中删除重复文件的副本
			DeleteFile(curIt->second.c_str());//在磁盘全部文件中删除重复文件的副本
			++count;
		}
		++curIt;
	}
	_filetoMd5.erase(curMD5);
	_md5toFiles.erase(curMD5);	
	std::cout << count << "  files deleted!" << std::endl;
}


void FileManager::DeleteByMD5(const std::string& md5)
{
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "\tNot exist!" << std::endl;
		return;
	}
	std::cout << md5 << "共有 " << _md5toFiles.count(md5) << " 个文件" << std::endl;
	auto pairIt = _md5toFiles.equal_range(md5);
	auto curIt = pairIt.first;
	++curIt;
	int count = 0;
	while (curIt != pairIt.second)
	{
		_files.erase(curIt->second);		
		DeleteFile(curIt->second.c_str());
		++count;
		++curIt;
	}	
	curIt = pairIt.first;
	while (curIt != pairIt.second)
	{
		_filetoMd5.erase(curIt->second);
		++curIt;
	}
	curIt = pairIt.first;
	_md5toFiles.erase(curIt, pairIt.second);
	std::cout << count << " files deleted!" << std::endl;
}


void FileManager::DeleteByMD52(const std::string& md5)
{
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "\tNot exist!" << std::endl;
		return;
	}
	auto it = _md5toFiles.find(md5);
	DeleteByName(it->second);
}


void FileManager::DeleteAllCopy()
{
	std::unordered_set<std::string>md5Set;
	for (const auto& p : _md5toFiles)
	{
		md5Set.insert(p.first);
	}
	for (const auto& md5 : md5Set)
	{
		DeleteByMD5(md5);
	}
}


void FileManager::ShowCopyList()
{
	int total = _md5toFiles.size();
	int count = 0;
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		int idx = 1;
		auto paitIt = _md5toFiles.equal_range(it->first);
		auto curIt = paitIt.first;
		std::cout << "当前MD5： " << it->first << std::endl;
		while (curIt != paitIt.second)
		{
			std::cout << "\t第" << idx << "个文件：" << curIt->second << std::endl;;
			++curIt;
			++idx;
			++count;
		}
		it = paitIt.second;
	}
	std::cout << "Total files :   " << total << " (实际值)"<<"\t" << count<<" (计算值)" << std::endl;
}


void FileManager::ShowAllFiles()
{
	for (const auto& f : _files)
	{
		std::cout << f << std::endl;
	}
	std::cout << "Total files :  " << _files.size() << std::endl;
}
