#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

string::size_type KMP(const string& S, int begin, const string& pattern)
{
	vector<int> pf(pattern.length());

	pf[0] = 0;
	for(int k = 0, i = 1; i < pattern.length(); ++i)
	{
		while((k > 0) && (pattern[i] != pattern[k]))
			k = pf[k - 1];

		if(pattern[i] == pattern[k])
			k++;

		pf[i] = k;
	}

	for(int k = 0, i = begin; i < S.length(); ++i)
	{
		while((k > 0) && (pattern[k] != S[i]))
			k = pf[k - 1];

		if(pattern[k] == S[i])std::cout << i + 1 << "\t"; //для просмотра входов
		k++;

		if(k == pattern.length())
			return (i - pattern.length() + 1); //либо продолжаем поиск следующих вхождений

	}

	return (string::npos);
	std::cout << string::npos;
}

int main() {
	string ss;
	char arr[] = "";
	setlocale(LC_ALL, "ru");

	ifstream in("E:\\heySyka.txt"); // окрываем файл для чтения
	while(!in.eof()) {
		ss = "";
		getline(in, ss);
	//	cout << ss << endl;
	}
	in.close();

	string pattern = "get";
	int begin = 1;

	printf("\n");
	KMP(ss, begin, pattern);
	return 0;
}