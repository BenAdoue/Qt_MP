
#ifndef MAPSSOLVER_H_
#define MAPSSOLVER_H_
#define CRT_SECURE_NO_WARNINGS
#include<vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace MapsSolver
{	
	using std::vector;
	using std::cout;
	using std::cerr;
	using std::endl;
	using std::string;

	bool readPGM(const string& filename, vector<vector<uint8_t>>& image);
	class PGMMapProcesser
	{
	public:
		int width;		// 宽
		int height;		// 高
		int maxGray;	// 最大灰度值
		int mapType;	// 地图类型
		unsigned char* mapData; //地图数据指针

	};
}// namespace MapsSolver



#endif
