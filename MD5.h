#pragma once
#include <string>

const int CHUNK_BYTE = 64;
typedef unsigned int uint32;


class MD5
{
public:
	MD5();

	//位运算处理函数
	uint32 F(uint32 x, uint32 y, uint32 z)
	{
		return   (x & y) | ((~x) & z);
	}

	uint32 G(uint32 x, uint32 y, uint32 z)
	{
		return   (x & z) | (y & (~z));
	}

	uint32 H(uint32 x, uint32 y, uint32 z)
	{
		return    x ^ y ^ z;
	}

	uint32 I(uint32 x, uint32 y, uint32 z)
	{
		return   y ^ (x | (~z));
	}

	//循环左移
	uint32 LeftShift(uint32 n, int shiftn)
	{
		int m = shiftn % 32;
		return (n << m) | (n >> (32 - m));
	}

	//初始化函数
	void Init();
	//重置函数
	void Reset();

	//计算一个处理单位的MD5值
	void CalMD5(uint32* chunk);
	//填充并计算最后一个处理单位的MD5值
	void CalFinalMD5();

	//把整数转换成16进制字符串
	std::string Int2StringH(uint32 n);

	//获取字符串的MD5值
	std::string GetStringMD5(const std::string& str);
	//获取文件的MD5值
	std::string GetFileMD5(const char* filePath);

private:
	static int _s[CHUNK_BYTE];      //循环移位的位数
	uint32 _k[CHUNK_BYTE];         //k[i]	
	char _chunk[CHUNK_BYTE];    //数据块 64字节

	uint32 _lastByte;                            //最后一块数据的字节数	
	uint32 _allBytes;                            //总字节数

	uint32 _a;                                     //MD5信息
	uint32 _b;
	uint32 _c;
	uint32 _d;
};