#include<stdio.h>

int main(void) 
{
    void rotationEncryption();
    void rotationDecryption();
    char option;
    
    option = 'b'; //Add scanf() before finishing project.
    //----------------------------------------------------------------------------------------
    //Menu printed to screen: 
   
    printf("############################################################\n");
    printf("# Please select an option from the menu below:             #\n");
    printf("#                                                          #\n");
    printf("# (a) Rotation encryption      (b) Rotation decryption     #\n");
    printf("# (c) Substitution encryption  (d) Substitution decryption #\n");
    printf("#                                                          #\n");
    printf("############################################################\n");

    //----------------------------------------------------------------------------------------
    
    scanf(" %c", &option);
        
    //----------------------------------------------------------------------------------------
    /*Runs the corresponding program based on the user input, and also returns an error message
      if the user inputs an invalid option.                                                    */ 
    
    switch (option)
    {
        case 97:
            rotationEncryption();
            break;
            
        case 98:
            rotationDecryption();
            break;
        
        default: 
            printf("ERROR: Enter a valid menu option");
            break;
    }
    
    //----------------------------------------------------------------------------------------
    
    return 0;
}

//---------------------------------------------------------------------------------------------

void rotationEncryption()
{
    char text[51];
    int key = 0;
    int count = 0;
    
    printf("Please enter some text to be encoded (Max 50 characters):\n");
    gets(text);
    printf("\nEnter the key for encryption (Must be between 0 and 25):\n");
    scanf(" %i", &key);
    
    do
    {
        if (text[count] >= 65 && text[count] <= 90-key)
        {
            text[count] += key;
        }
        else if (text[count] >= 97 && text[count] <= 122-key)
        {
            text[count] += key-32;
        }
        else if (text[count] > 90-key && text[count] <= 90)
        {
            text[count] += key-26;
        }
        else if (text[count] > 122-key && text[count] <= 122)
        {
            text[count] += key-32-26;
        }
        else
        {
            text[count] = text[count];
        }
        
        count++;
    } while (text[count] != 0);
    
    printf("Encoded text is: %s\n", text);
    
}

//----------------------------------------------------------------------------------------------------

void rotationDecryption()
{
    char eText[51]; //Encrypted text
    int key = 0;
    int count = 0;
    
    printf("Please enter encrypted text to be decoded:\n");
    gets(eText);
    printf("Enter the decryption key:\n");
    scanf(" %i", &key);
    
    do
    {
        if (eText[count] >= 65+key && eText[count] <= 90)
        {
            eText[count] -= key;    
        }
        else if (eText[count] >= 97+key && eText[count] <= 122)
        {
            eText[count] += -key-32;
        }
        else if (eText[count] < 65+key && eText[count] >= 65)
        {
            eText[count] += -key+26;
        }
        else if (eText[count] >= 97 && eText[count] < 97+key)
        {
            eText[count] += -key+26-32;
        }
        else
        {
            eText[count] = eText[count];
        }
        
        count++;
    } while (eText[count] != 0);
    
    printf("Decrypted text is: %s\n", eText);
}


