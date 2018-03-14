#include<iostream>
#include<cstdio>
#include<set>
#include<fstream>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
	fstream filea("D:\\Github\\NWPU-shangjikaoshi\\NWPU_shangjikaoshi\\NWPU_shangjikaoshi\\a.txt");
	fstream fileb("D:\\Github\\NWPU-shangjikaoshi\\NWPU_shangjikaoshi\\NWPU_shangjikaoshi\\b.txt");
		set<int> A;
		set<int> B;
		set<int> C,D,E;
		set<int>::iterator op;
		int na, nb;
		filea>> na;
		for (int i = 0; i < na; i++)
		{
			int temp;
			filea >> temp;
			A.insert(temp);
		}
		fileb>> nb;
		for (int i = 0; i < nb; i++)
		{
			int temp;
			fileb >> temp;
			B.insert(temp);
		}
		set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
		for (op = C.begin(); op!= C.end(); op++)
		{
			//if ( != C2.begin())cout << ", ";
			cout << *op<<' ';
		}
		cout<< endl;
		set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(D, D.begin()));
		for (op = D.begin(); op != D.end(); op++)
		{
			//if ( != C2.begin())cout << ", ";
			cout << *op << ' ';
		}
		cout << endl;
		set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(E, E.begin()));
		for (op = E.begin(); op != E.end(); op++)
		{
			//if ( != C2.begin())cout << ", ";
			cout << *op << ' ';
		}
		cout<<endl;
		filea.close();
		fileb.close(); 
		system("pause");
	return 0;
}