
#include "MapsSolver.h"

namespace MapsSolver
{
    // ��ȡPGM�ļ��������ݴ����ά����
    bool readPGM(const string& filename, vector<vector<uint8_t>>& image) {
        FILE* file = fopen(filename.c_str(), "rb");  // �Զ����Ʒ�ʽ���ļ�
        if (!file) {
            cerr << "Error: Could not open file " << filename << endl;
            return false;
        }

        char header[3];
        // ��ȡ�ļ�ͷ
        if (fread(header, 1, 2, file) != 2 || header[0] != 'P' || header[1] != '5') {
            cerr << "Error: Not a P5 PGM file!" << endl;
            fclose(file);
            return false;
        }
        cout << "header:" << header[0] << header[1] << int(header[2]) << endl;

        // �������к�ע��
        char ch;
        ch = fgetc(file);
        cout << "ch0 = " << ch << "chint = " << int(ch) << endl;
        ch = fgetc(file);
        cout << "ch01 = " << ch << "chint = " << int(ch) << endl;
        while (ch == '#') {
            // ��ȡ������ע����
            cout << "ch1 = " << ch << endl;
            while ((ch = fgetc(file)) != '\n' && ch != EOF) { cout << "ch = " << ch << endl; };
        }
        cout << "ch2 = " << int(ch) << endl;
        // ��ȡ��Ⱥ͸߶�
        ungetc(ch, file); // �˻���һ����#�ַ�
        int width, height;
        int ret = fscanf(file, "%d %d", &width, &height);
        cout << "ret = " << ret << endl;
        if (ret != 2) {
            cerr << "Error: Could not read image dimensions!" << endl;
            fclose(file);
            return false;
        }

        // ��ȡ���Ҷ�ֵ
        int maxValue;
        if (fscanf(file, "%d", &maxValue) != 1 || maxValue != 255) {
            cerr << "Error: Unsupported max value or invalid format!" << endl;
            fclose(file);
            return false;
        }

        // ������ĩ�Ļ��з�
        fgetc(file);

        // ��ʼ����ά����
        image.resize(height, vector<uint8_t>(width));

        // ��ȡͼ������
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
