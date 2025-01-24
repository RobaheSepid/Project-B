#include <iostream>
#include <string>
#include <vector>
using namespace std;

string bigMultiply(string , string);
int main() {
    string num1, num2;
    cout << "Please Enter Your First Number: ";
    cin >> num1;
    cout << "--------------------\nPlease Enter Your Second Number: ";
    cin >> num2;
    int num1len=num1.size();
    int num2len=num2.size();
    for(int i=0;i<num1len;i++){
    	if(i==0 &&num1[i]=='-')
    		continue;
    	if(!(num1[i]>= '0' &&num1[i]<= '9')){
    		cout << "--------------------\nPlease Enter First Number Correctly!\nLike:\n1234\nYou Enter Incorrect Charcter Like:\n'a,A,~,etc'\n";
	    	system("pause");
	    	return 0;	
		}
	}
	for(int i=0;i<num2len;i++){
		if(i==0 && num2[i]=='-')
    		continue;
		if(!(num2[i]>='0'&&num2[i]<='9')){
    		cout << "--------------------\nPlease Enter Second Number Correctly!\nLike:\n1234\nYou Enter Incorrect Charcter Like:\n'a,A,~,etc'\n";
	    	system("pause");
	    	return 0;	
		}
	}
    //negative numbers?
    bool isNegative1 = num1[0] == '-';
    bool isNegative2 = num2[0] == '-';
    if (isNegative1)
		num1 = num1.substr(1);
    if (isNegative2) 
		num2 = num2.substr(1);
    string multiplyResult = bigMultiply(num1, num2);
    if (isNegative1 != isNegative2)
		multiplyResult = '-' + multiplyResult;
    cout << "Result: " << multiplyResult << endl << "--------------------\n";
	system("pause");
    return 0;
}
string bigMultiply(string num1, string num2) {// this function multiply two large number
    if (num1 == "0" || num2 == "0") 
		return "0";
    vector<int> result(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }
    string strResult = "";
    bool nmZero = true;
    for (int num : result) {//for-each loop
        if (nmZero && num == 0) 
		continue;
        nmZero = false;
        strResult += num + '0';
    }
    return strResult;
}