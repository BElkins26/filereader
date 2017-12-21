#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *word;
	char curchar[1];
	int count=0;
	int wordsize=2;
	FILE *file;
	word = malloc(wordsize * sizeof(char));
	if((file=fopen(argv[1], "rb"))==NULL)
	{	
		printf("IMPROPER FILE");
		return 1;
	}
	while(fread(curchar, sizeof(char), 1, file) > 0)
	{
		if(count >= wordsize)
		{
			word =realloc(word, (wordsize*2) * sizeof(char));
			wordsize = wordsize * 2;
		} 
		if((curchar[0] <= 126 && curchar[0] >= 32) || curchar[0] == 9)
		{
			
			word[count] = curchar[0];
			count++;
		}
		else if(count >= 4)
		{
			word[count] = '\0';
			printf("%s\n", word);
			count = 0;			
		}
		else
		{
			count = 0;
		}
	}
	free(word);
	return 0;
}
