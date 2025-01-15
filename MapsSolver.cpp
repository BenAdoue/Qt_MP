
#include "MapsSolver.h"

namespace MapsSolver
{
    // 读取PGM文件并将数据存入二维数组
    bool readPGM(const string& filename, vector<vector<uint8_t>>& image) {
        FILE* file = fopen(filename.c_str(), "rb");  // 以二进制方式打开文件
        if (!file) {
            cerr << "Error: Could not open file " << filename << endl;
            return false;
        }

        char header[3];
        // 读取文件头
        if (fread(header, 1, 2, file) != 2 || header[0] != 'P' || header[1] != '5') {
            cerr << "Error: Not a P5 PGM file!" << endl;
            fclose(file);
            return false;
        }
        cout << "header:" << header[0] << header[1] << int(header[2]) << endl;

        // 跳过空行和注释
        char ch;
        ch = fgetc(file);
        cout << "ch0 = " << ch << "chint = " << int(ch) << endl;
        ch = fgetc(file);
        cout << "ch01 = " << ch << "chint = " << int(ch) << endl;
        while (ch == '#') {
            // 读取并丢弃注释行
            cout << "ch1 = " << ch << endl;
            while ((ch = fgetc(file)) != '\n' && ch != EOF) { cout << "ch = " << ch << endl; };
        }
        cout << "ch2 = " << int(ch) << endl;
        // 读取宽度和高度
        ungetc(ch, file); // 退回上一个非#字符
        int width, height;
        int ret = fscanf(file, "%d %d", &width, &height);
        cout << "ret = " << ret << endl;
        if (ret != 2) {
            cerr << "Error: Could not read image dimensions!" << endl;
            fclose(file);
            return false;
        }

        // 读取最大灰度值
        int maxValue;
        if (fscanf(file, "%d", &maxValue) != 1 || maxValue != 255) {
            cerr << "Error: Unsupported max value or invalid format!" << endl;
            fclose(file);
            return false;
        }

        // 跳过行末的换行符
        fgetc(file);

        // 初始化二维数组
        image.resize(height, vector<uint8_t>(width));

        // 读取图像数据
        for (int i = 0; i < height; ++i) {
            if (fread(image[i].data(), 1, width, file) != width) {
                cerr << "Error: Failed to read pixel data!" << endl;
                fclose(file);
                return false;
            }
        }
        fclose(file);
        return true;
    }
}// namespace MapsSolver
