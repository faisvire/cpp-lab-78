#include <iostream>
using namespace std;
size_t LengthString(const char* str) {
	size_t len = 0;
	while (*str != '\0') {
		++len;
		++str;
	}
	return len + 1;
}
void copyString(char* strk2, const char* strk, int strk2Size) {
	int i = 0;
	while (strk[i] != '\0' && i < strk2Size - 1) {
		strk2[i] = strk[i];
		++i;
	}
	strk2[i] = '\0';
}