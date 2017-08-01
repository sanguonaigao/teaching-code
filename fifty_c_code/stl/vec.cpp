/*************************************************************************
    > File Name: vec.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 六  5/21 11:19:58 2016
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<int> v;
	for(int i = 0;i<100000000;i++)
	{
		v.push_back(i);
	}
//	printf("count = %lu\n", v.size());
	printf("%d\n",v.empty());
	return 0;
}
