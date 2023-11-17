#include "LevelReader.hpp"

LevelReader::LevelReader()
{}

LevelReader::~LevelReader()
{}

std::string LevelReader::SheetReader(const char* path)
{
	std::string text;

	std::ifstream file(path);

	file.seekg(0, std::ios::end);

	int size;
	size = file.tellg();

	file.seekg(0, std::ios::beg);

	char a;

	for (int i = 0; i < size; i++)
	{
		file.get(a);
		text += a;
	}

	return text;
}