#include<bits/stdc++.h>
using namespace std;

void printSubs(string inp, string opt) {
	if(inp.empty())
	{
		cout<<"'"<<opt<<"'"<<endl;
		return;
	}
	
	printSubs(inp.substr(1), opt);
	printSubs(inp.substr(1),opt+inp[0]);
}

int main() {
	string inp;
	cin>>inp;
	printSubs(inp,"");
	return 0;
}
