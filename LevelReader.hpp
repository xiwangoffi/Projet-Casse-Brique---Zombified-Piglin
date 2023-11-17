#pragma once
#include "App.hpp"

class LevelReader {
private:
	
public:
	LevelReader();
	~LevelReader();

	static std::string SheetReader(const char* path);
};