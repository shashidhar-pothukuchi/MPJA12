#include<iostream>
#include"filehandle.h"

using namespace std;

int main()
{
	struct customer cu;
	bankfiles b;
	b.put();
	cu = b.get(123456);
	cout<<cu.name;
}
