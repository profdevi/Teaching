#include <stdio.h>
#include <stdbool.h>

///////////////////////////////////////////
void MGetString(char *buf,int buflen);  // Get string from user into buffer
bool MIsBinary(const char *str); 	// =true if str is binary
bool MIsSymbol(char ch);		//check if 0 or 1


///////////////////////////////////////////
int main(void)
	{
	char inp[100];
	printf("Enter a string : ");
	MGetString(inp,100);

	if(MIsBinary(inp)==true)
		{
		printf("%s is a binary integer\n",inp);
		}
	else
		{
		printf("%s is not a binary integer\n",inp);
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
bool MIsBinary(const char *buf)
	{
	int state=1;

	int i;
	for(i=0;buf[i]!=0;i=i+1)
		{
		if(state==1)
			{
			if(MIsSymbol(buf[i])==true)
				{
				state=2;
				continue;
				}

			return false;
			}
		else if(state==2)
			{
			if(MIsSymbol(buf[i])==true)
				{
				continue;
				}

			return false;
			}
		}

	return true;
	}


///////////////////////////////////////////////
bool MIsSymbol(char ch)
	{
	if(ch=='0' || ch=='1')
		{
		return true;
		}

	return false;
	}

