#pragma once
#include<string>
#include<filesystem>

namespace File
{
	std::string GetFilePath();
	bool SetFilePath(const std::string& filePath);
	bool FileExists(const std::string& filepath);
	int GetFileSize(const std::string& filepath, int& size);
	bool ReadFile(const std::string& filepath, std::string& buffer);

}
