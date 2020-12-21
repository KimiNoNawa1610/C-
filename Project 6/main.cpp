#include <iostream>
#include<string>
#include<cstring>
#include<ctype.h>
using namespace std;

void transform(char*, char*);
bool testPalindrome(char*);

int main() {
	string s;
	getline(cin, s);
	//declares a constant char[] and puts the contents of s into it
	const char* input = s.c_str();
	//make a new char[] of length s + 1 so we can have \0 at the end
	char* test = new char[s.length() + 1];
	//copies char[] input to char[] test
	strcpy(test, input);
}

void transform(char* raw, char* testStr) {
	int i = 0;
	int j = 0;
	while (*raw != '\0') {
		if (isalpha(*raw)) {
			*testStr++ = tolower(*raw++);
		}
		raw++;
	}
	*testStr  = '\0';
}

bool testPalindrome(char* str) {
	int i = 0;
	int j = 0;
	int index = 0;
	while (*str++ != '\0') {
		index++;
	}
	int limit = index / 2;
	j = index;
	while (limit != 0) {
		cout << str[i] << " | " << str[j];
		if (str[i] != str[j]) {
			return false;
			break;
		}
		i++;
		j--;
		limit--;
	}
	return true;
}