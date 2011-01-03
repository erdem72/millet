#include<stdio.h>
#include<string.h>

int main(int argv,char** args)
{
	int dos2unix = 0;
	int unix2dos = 0;
	if(argv != 2)
	{
		printf("usage:convert src\n");
		exit(0);
	}
	if(strncmp(args[0],"dos2unix",8) == 0)
	{
		dos2unix = 1;
	}else
		unix2dos = 1;

	FILE *in = fopen(args[1], "rb");
	FILE *out = fopen("tmp", "wb");
	char ch;
	while((ch = fgetc(in)) != EOF)
	{
		if(ch == '\r' && dos2unix)
			continue;
		else if(ch == '\n' && unix2dos)
			fputc('\r',out);
		fputc(ch,out);
	}
	fclose(in);
	fclose(out);
	in = fopen("tmp","rb");
	out = fopen(args[1],"wb");
	while((ch = fgetc(in)) != EOF)
	{
		fputc(ch,out);
	}
	fclose(in);
	fclose(out);
	remove("tmp");
}