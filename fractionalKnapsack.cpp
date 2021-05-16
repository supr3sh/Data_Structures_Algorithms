#include<bits/stdc++.h>
using namespace std;

void solve(int weight[], int profit[], int n, int cap) {
	int ratio[n];
	
	for(int i=0;i<n;i++) {
		ratio[i] = profit[i]/weight[i];
	}
	
	std::sort(ratio, ratio+n);
	double total=0;
	for(int i=n-1;i>=0;i--) {
		int j=0;
		for(; j<n;j++)
		{
			if(profit[j]/weight[j]==ratio[i])
				break;
		}
		if(cap > 0 && weight[j]<=cap) {
			cout<<"Taken : "<<weight[j]<<" Full."<<endl;
			cap -= weight[j];
			total += profit[j];
		}
		else if(cap > 0) {
			cout<<"Taken : "<<weight[j]<<" "<<(double)cap/weight[j]<<endl;
			total += profit[j]*((double)cap/weight[j]);
			break;
		}
	}
	cout<<"And total profit : "<<total<<endl;
}

int main() {
	int n=3;
	int profit[] = {60,100,120};
	int weight[] = {10,20,30};
	int cap = 50;
	solve(weight, profit, n, cap);
}
