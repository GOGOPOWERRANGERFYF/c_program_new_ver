#include <stdio.h>
#include <wchar.h>
// 输出中文需要的头文件
#include <locale.h>
int charString(void);
int wideCharString(void);
int toHexadecimal(void);

int main(void) {
	// vim输入unicode:
	//	insert模式下ctrl+v
	//	根据unicode编码的范围选择输入u或U,然后输入unicode码
	//printf("%s\n", "🤖主函数启动.../");
	
	// 运行中发现C的窄字符串和宽字符串不能同时输出...
	// 先输出一种字符串则另一种字符串无法输出...
	
	//charString();
	//wideCharString();
	
	toHexadecimal();

	printf("%zd\n", sizeof(*"xxx"));
	return 0;
}

int charString(void) {
	// char c = '哈'; 会报错,因为'哈'已经超出了ascii的编码范围
	char ca[] = "哈";
	printf("%s, %zd\n", ca, sizeof(ca));
	return 0;
}

int wideCharString(void) {
	setlocale(LC_ALL, "zh_CN.UTF-8");
	wprintf(L"%ls\n", L"🤖wideCharString函数开始执行...");
	
	wchar_t wct1 = L'💩';
	wprintf(L"%lc\n", wct1);
	wchar_t wct2 = L'屎';
	wprintf(L"%lc %zd %x\n", wct2, sizeof(wct2), wct2);
	return 0;
}

int toHexadecimal(void) {
	int i1 = 17;
	printf("%x\n", i1);

	float f1 = 1.0;
	int * conversion_p = (int *)&f1;
	printf("%x\n", *conversion_p);
	return 0;
}


