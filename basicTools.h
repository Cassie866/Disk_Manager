#pragma once
#include <iostream>
#include <io.h>
#include <string>
#include <unordered_set>

//ɨ�����
void SearchDisk(const std::string& path, std::unordered_set<std::string>& subFiles);

//ɾ���ļ�
void DeleteFile(const char* fileName);