#include<iostream>
#include<unordered_set>

using  namespace std;

int maxVowels(string s, int k){
	int maxCount = 0;
	int vcount = 0;
	unordered_set<char>  vowels = {'a', 'i', 'e', 'o', 'u'};
	
	for(int i=0; i<k; i++)
		if(vowels.find(s[i]) != vowels.end()) vcount++;
	maxCount =  vcount;
	
	int l = 0, r = k-1;
	while(r < s.length()){
		if(vowels.find(s[l]) != vowels.end()) vcount--;
		l++; 
		r++;
		if(vowels.find(s[r]) != vowels.end()) vcount++;
		maxCount = max(maxCount, vcount);
	}
	return maxCount;
}

int  main (){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	
	int k;
	cout<<"Enter k: ";
	cin>>k;
	
	cout<<"Max count of vowel substring length "<<k<<": ";
	cout<<maxVowels(str, k);
	return 0;
}
