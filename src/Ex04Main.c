#include <stdio.h>
#include <stdbool.h>

///////////////////////////////////////////
void MGetString(char *buf,int buflen);  // Get string from user into buffer
int MOctalToInteger(const char *str); 	// convert octal string into integer
bool MIsOctalChar(char ch);		//check if char  is 0,1,2,...,7


///////////////////////////////////////////
int main(void)
	{
	char inp[100];
	printf("Enter a string : ");
	MGetString(inp,100);

	printf("Octal %s is integer %d\n",
			inp,MOctalToInteger(inp) );

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
int MOctalToInteger(const char *buf)
	{
	int state=1;

	int value;

	int i;
	for(i=0;buf[i]!=0;i=i+1)
		{
		if(state==1)
			{
			if(MIsOctalChar(buf[i])==true)
				{
				state=2;
				value=buf[i]-'0';
				continue;
				}

			return -1;
			}
		else if(state==2)
			{
			if(MIsOctalChar(buf[i])==true)
				{
				value=8*value+(buf[i]-'0');
				continue;
				}

			return -1;
			}
		}

	return value;
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

