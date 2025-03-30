#include <stdio.h>
#include <stdbool.h>

///////////////////////////////////////////
void MGetString(char *buf,int buflen);  // Get string from user into buffer
bool MIsOctal(const char *str); 	// =true if str is octal
bool MIsOctalChar(char ch);		//check if char  is 0,1,2,...,7


///////////////////////////////////////////
int main(void)
	{
	char inp[100];
	printf("Enter a string : ");
	MGetString(inp,100);

	if(MIsOctal(inp)==true)
		{
		printf("%s is an octal integer\n",inp);
		}
	else
		{
		printf("%s is not an octal integer\n",inp);
		}

	return 0;
	}


////////////////////////////////////////////
void MGetString(char *buf,int buflen)
	{
	// Ue fgsts from the standard input library
	fgets(buf,buflen,stdin);

	// clean up '\r' and '\n'
	int i;
	for(i=0;buf[i]!=0;i=i+1)
		{
		if(buf[i]=='\r' || buf[i]=='\n')
			{
			buf[i]=0;
			return;
			}
		}
	}


////////////////////////////////////////////
bool MIsOctal(const char *buf)
	{
	int state=1;

	int i;
	for(i=0;buf[i]!=0;i=i+1)
		{
		if(state==1)
			{
			if(MIsOctalChar(buf[i])==true)
				{
				state=2;
				continue;
				}

			return false;
			}
		else if(state==2)
			{
			if(MIsOctalChar(buf[i])==true)
				{
				continue;
				}

			return false;
			}
		}

	return true;
	}


///////////////////////////////////////////////
bool MIsOctalChar(char ch)
	{
	if(ch>='0' && ch<='7')
		{
		return true;
		}

	return false;
	}

