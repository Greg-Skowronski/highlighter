#include <iostream>
#include <string.h>
using namespace std;


int main(){
	int C;
	int l;
	int k, m;
	char word[200];
	unsigned char result[50][200][2];
	int num[50][200];
	cin >> C;
	fflush(stdin);
	if(C>=1 && C<=50) for(int j=0; j<C; j++){
		cin >> word;
		//fgets(word,200,stdin);
		//word[strlen(word)-1]='\0';
		l = strlen(word);
		k=0;
		m=0;
		for(int i=0; i<l-1; i++){
			if(word[i]==word[i+1]){
				k++;
			}else{
				result[j][m][0]=word[i];
				result[j][m][1]=k+1;//+49;
				k=0;
				m++;
			}
			if(i==l-2 && word[i]!=word[i+1]){
				result[j][m][0]=word[i+1];
				result[j][m][1]=1;//49;
			}else if(i==l-2 && word[i]==word[i+1]){
				result[j][m][0]=word[i];
				result[j][m][1]=k+1;//+49;
			}
		}
		if(l==1){
			result[j][0][0]=word[0];
			result[j][0][1]=1;//49;
		}
		for(int i=0; i<m+1; i++){
			cout << result[j][i][0]; //<< result[j][i][1];
			num[j][i] = (int)result[j][i][1];// - 48;
			if(num[j][i]>2) cout << num[j][i];
			if(num[j][i]==2) cout << result[j][i][0];
		}
		cout << endl;
		m=0; k=0;
	}
	return 0;
}

