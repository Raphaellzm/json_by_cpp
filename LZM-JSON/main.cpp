#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "json.h"
using namespace lzm::json;

void test01()
{
	Json v1;
	Json v2 = true;
	Json v3 = 123;
	Json v4 = 1.23;
	Json v5 = "hello world";

	bool b = v2;
	int i = v3;
	double f = v4;
	const string & s = v5;
}

void test02()
{
	Json arr;
	arr[0] = true;
	arr[1] = 123;

	arr.append(1.23);
	arr.append("hello world");

	std::cout << arr.str() << std::endl;

	bool b = arr[0];
	int i = arr[1];
	double f = arr[2];
	const string & s = arr[3];
	std::cout << b << endl;
	std::cout << i << endl;
	std::cout << f << endl;
	std::cout << b << endl;
}

void test03()
{
	Json obj;
	obj["bool"] = true;
	obj["int"] = 123;
	obj["double"] = 1.23;
	obj["str"] = "hello world";

	std::cout << obj.str() << std::endl;
}

void test04()
{
	Json arr;
	arr[0] = true;
	arr[1] = 123;
	arr[2] = 1.23;
	arr[3] = "hello world";
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << (*it).str() << std::endl;
	}
}

void test05()
{
	Json arr;
	arr[0] = true;
	arr[1] = 123;
	arr[2] = 1.23;
	arr[3] = "hello world";

	std::cout << arr.has(0) << std::endl;
	std::cout << arr.has(4) << std::endl;
	arr.remove(0);
	std::cout << arr.str() << std::endl;
}

void test06()
{
	Json obj;
	obj["bool"] = true;
	obj["int"] = 123;
	obj["double"] = 1.23;
	obj["str"] = "hello world";

	std::cout << obj.has("str") << std::endl;

	obj.remove("str");
	std::cout << obj.str() << std::endl;
}

//2.11 parser test
void ptest01()
{
	const string & str = "[\"a\",1,2,3,true,false,null,-1,-1.23,33.4]";
	Json v;
	v.parse(str);
	std::cout << v.str() << std::endl;
}

void ptest02()
{
	const string & str = "{\"a\":1,\"b\":2,\"c\":3}";
	Json v;
	v.parse(str);
	std::cout << v.str() << std::endl;
}

void ptest03()
{
	ifstream fin("./test.json");
	stringstream ss;
	ss << fin.rdbuf();
	const string & str = ss.str();

	Json v;
	v.parse(str);
	string name = v["axes"][0]["name"];
	int version = v["meta"]["version"];
	std::cout << name << std::endl;
	std::cout << version << std::endl;
	//std::cout << v.str() << std::endl;
}

int main()
{
	ptest03();
	return 0;
}

