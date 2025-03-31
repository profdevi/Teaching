#include <stdio.h>
#include <stdbool.h>

///////////////////////////////////////////
void MGetString(char *buf,int buflen);  // Get string from user into buffer
bool IsSpace(char ch);		// check if ch is a word seperator
bool IsChar(char ch);   // Check if ch is a char in  word
int GetWordCount(char  *str);	// Get Word count in string str

///////////////////////////////////////////
int main(void)
	{
	char inp[100];
	printf("Enter a string : ");
	MGetString(inp,100);

	printf("Word Count = %d\n",GetWordCount(inp) );

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
bool IsSpace(char ch)		// check if ch is a word seperator
	{
	if(ch==' '  || ch=='\r' || ch=='\n')
		{
		return true;
		}

	return false;
	}


//////////////////////////////////////////////
bool IsChar(char ch)   // Check if ch is a char in  word
	{
	// Assume that word char is anything not a space.
	if(IsSpace(ch)==true)
		{
		return false;
		}

	return true;
	}

/////////////////////////////////////////////
int GetWordCount(char  *str)	// Get Word count in string str
	{
	int count=0;
	int state=1;

	int i;
	for(i=0;str[i]!=0;++i)
		{
		if(state==1)
			{
			if(IsChar(str[i])==true)
				{
				count=count+1;
				state=2;
				continue;
				}

			continue;
			}
		else if(state==2)
			{
			if(IsSpace(str[i])==true)
				{
				state=1;
				continue;
				}

			continue;
			}
		}

	return count;	
	}



