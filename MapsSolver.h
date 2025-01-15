
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
		int width;		// ��
		int height;		// ��
		int maxGray;	// ���Ҷ�ֵ
		int mapType;	// ��ͼ����
		unsigned char* mapData; //��ͼ����ָ��

	};
}// namespace MapsSolver



#endif
