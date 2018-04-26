#include <bits/stdc++.h>
using namespace std;
int LPS[1000000];
void Compute(string Pattern){
    int Length=0;
    LPS[0]=0;
    int i=1;
    while(i<Pattern.size()){
        if (Pattern[i]==Pattern[Length]){
            Length++;
            LPS[i]=Length;
            i++;
        }else{
            if (Length!=0){
                Length=LPS[Length-1];
            }else{
                LPS[i]=0;
                i++;
            }
        }
    }
}
vector<int> KMP_Search(string Pattern, string Target){
    vector<int>Results;
    Compute(Pattern);
    int i=0, j=0;
    while(i<Target.size()){
        if (Pattern[j]==Target[i]){
            i++;
            j++;
        }
        if (j==Pattern.size()){
            Results.push_back(i-j);
            j=LPS[j-1];
        }
        else if (i<Target.size() && Pattern[j]!=Target[i]){
            if (j!=0)
                j=LPS[j-1];
            else
                i++;
        }
    }
    return Results;
}
int main(){
	string Find, Target;
	cin>>Target>>Find;
	for (int i=0; i<KMP_Search(Find, Target).size(); i++)
		cout<<KMP_Search(Find, Target)[i]<<' ';
	return 0;
}