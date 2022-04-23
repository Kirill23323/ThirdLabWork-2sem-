#include<iostream>
#include "String.h"
#include <clocale>
int main() 
{
	setlocale(LC_ALL, "Rus");
	TString* split;
	char* b = new char[5];
	for (int i = 0; i < 5; i++) 
	{
		b[i] = '4';
	}
	b[4] = 0;
	TString text1(10, 'A');
	std::cout << text1 << std::endl;
	TString text2("student");
	std::cout << text2 << std::endl;
	TString text3 = text2;
	std::cout << text3 << std::endl;
	TString text4;
	text4 = text3 + text1;
	std::cout << text4 << std::endl;
	TString text5;
	text5 = text2 + b;
	std::cout << text5 << std::endl;
	TString text6("dsffsdf");
	text6 += b;
	std::cout << text6 << std::endl;
	TString text7("dsfafsgsdgw");
	text7 += text2;
	std::cout << text7 << std::endl;
	std::cout << text1[0] << std::endl;
	if (text3 == text2) 
	{
		std::cout << "Text3 = Text2" << std::endl;
	}
	if (text1 != text2)
	{
		std::cout << "Text1 != Text2" << std::endl;
	}
	if (text1 < text2)
	{
		std::cout << "Text1 < Text2" << std::endl;
	}
	if (text2 > text1)
	{
		std::cout << "Text2 > Text1" << std::endl;
	}
	TString text8;
	text8 = b;
	std::cout << text8 << std::endl;
	std::cout << "Index of 'u' in '" << text2 << "' == " << text2.Find('u') << "\t";
	TString text9("Hello from Russia");
	split = text9.Split(' ');
	std::cout << std::endl;
	for (int i = 0; i < text9.GetCount(); i++) 
	{
		std::cout << split[i] << std::endl;
	}
	TString text10;
	std::cout<< "¬ведите строку" << std::endl;
	std::cin >> text10;
	std::cout << text10 << std::endl;
	int* indexes = text4.Find(text1);
	std::cout << "Indexes of   '" << text1 << "'   in   '" << text4 << "'   ==  ";
	for (int i = 0; i < text4.GetCountOfFindIndexes(); i++)
		std::cout << indexes[i] << "  ";
	return 0;
}