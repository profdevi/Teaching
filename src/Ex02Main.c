#include <stdio.h>
#include <stdbool.h>

///////////////////////////////////////////
void MGetString(char *buf,int buflen);  // Get string from user into buffer
int MBinaryToInteger(const char *binstr);	// Convert binary string to integer
bool MIsSymbol(char ch);		//check if 0 or 1


///////////////////////////////////////////
int main(void)
	{
	char inp[100];
	printf("Enter a binary integer : ");
	MGetString(inp,100);

	printf("%s in binary  is the integer %d",
			inp,MBinaryToInteger(inp) );

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
int MBinaryToInteger(const char *binstr)
    {
    int state=1;
    
    int value;
    
    int i;
	for(i=0;binstr[i]!=0;i=i+1)
        {
        if(state==1)
            {
            if(MIsSymbol(binstr[i])==true)
                {
                value=(binstr[i]-'0');
                state=2;
                continue;
                }
                
            // Bad char in input, return  -1
            return -1;
            }
        else if(state==2)
            {
            if(MIsSymbol(binstr[i])==true)
                {
                value=2*value+(binstr[i]-'0');
                continue;
                }
            
            // Bad char in input. Return -1
            return -1;
            }    
        
        // Bad state reached, Return -1
        return -1;
        }
        
    // Return integer for binary number string
    return value;
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

