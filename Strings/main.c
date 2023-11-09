#include <stdio.h>
#include <stdlib.h>

int length(char s[])
{
	int i;

	for (i = 0; s[i] != 0; i++) {}

	return i;
}

char* to_upper(char* s)
{
	int len = length(s);
	char* new_str = (char*)malloc(len);

	for (int i = 0; s[i] != '\0'; i++)
		new_str[i] = s[i] - 32;

	return new_str;
}

int word_count(char* s) 
{
	int words = 1;

	for (int i = 1; s[i] != '\0'; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			words++;

	return words;
}

void reverse(char s[]) 
{
	int j = length(s) - 1;

	for (int i = 0; i < j; i++, j--)
	{
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
} 

int main() {
	char s[] = "benijamin";

	reverse(s);

	printf("%s\n", s);
}
