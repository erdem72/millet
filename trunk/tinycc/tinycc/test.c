short a = 3;
void f();

int main()
{
	static int a = 0;
	int i;
	for(i = 0; i < 3; i++)
	{
		int c = i;
		a += c;
	}
	f();
	return a;
}
void f()
{
	a++; 
}
/*typedef unsigned int uint;
__declspec(dllexport) int max(int a, uint b)
{
	return a > b ? a : b;
}
void f()
{
	static int a = 100;
	a++;
}
int main(void)
{
	static int a = 3.14;
	max(a, -1);
	f();
	printf("%d\n", a);
	return a;
}*/

/*
  int a = 300;
  char c = a;
*/