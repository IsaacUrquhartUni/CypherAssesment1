#include<stdio.h>

int main(void) 
{
    
    void menu();
    int exit;
    
    
    do 
    {
        menu();
        printf("\nExit? (1) Yes (2) No\n");
        scanf(" %i", &exit);
    } while (exit != 1);
       
    return 0;
}

//---------------------------------------------------------------------------------------------

void menu()
{
    void rotationEncryption();
    void rotationDecryption();
    void substitutionEncryption();
    void substitutionDecryption();
    char option = ' ';
    //Menu printed to screen: 
   
    printf("############################################################\n");
    printf("# Please select an option from the menu below:             #\n");
    printf("#                                                          #\n");
    printf("# (a) Rotation encryption      (b) Rotation decryption     #\n");
    printf("# (c) Substitution encryption  (d) Substitution decryption #\n");
    printf("#                                                          #\n");
    printf("############################################################\n");
    
    scanf(" %c", &option);
    
    
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
        
        case 99:
            substitutionEncryption();
            break;
        
        case 100:
            substitutionDecryption();
            break;
        
        default: 
            printf("ERROR: Enter a valid menu option");
            break;
    }
}

//---------------------------------------------------------------------------------------------

void rotationEncryption()
{
    char text[51];
    int key = 0;
    int count = 0;
    
    printf("Please enter some text to be encoded (Max 50 characters):\n");
    scanf(" %[^\n]%*c", text);
    printf("\nEnter the key for encryption (Must be between 0 and 25):\n");
    scanf("\n %i", &key);
    
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
    scanf(" %[^\n]%*c", eText);
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

//--------------------------------------------------------------------------------------------------------------

void substitutionEncryption()
{
    char text[51]; //Encrypted text
    int count = 0;
    
    printf("Please enter text to be encrypted:\n");
    scanf(" %[^\n]%*c", text);
    
    //Plain Text: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    //Encrypted:  DTIOXZMQAWLRVUYSEGJFHBPNKC
    
    do
    {
        if (text[count] >= 97 && text[count] <= 122)
        {
            text[count] -= 32;
        }
        switch (text[count])
        {
            case 65:
                text[count] = 'D';
                break;
            
            case 66:
                text[count] = 'T';
                break;
            case 67:
                text[count] = 'I';
                break;
            
            case 68:
                text[count] = 'O';
                break;
            
            case 69:
                text[count] = 'X';
                break;
            
            case 70:
                text[count] = 'Z';
                break;
                
            case 71:
                text[count] = 'M';
                break;
                
            case 72:
                text[count] = 'Q';
                break;
                
            case 73:
                text[count] = 'A';
                break;
                
            case 74:
                text[count] = 'W';
                break;
                
            case 75:
                text[count] = 'L';
                break;
                
            case 76:
                text[count] = 'R';
                break;
                
            case 77:
                text[count] = 'V';
                break;
                
            case 78:
                text[count] = 'U';
                break;
                
            case 79:
                text[count] = 'Y';
                break;
                
            case 80:
                text[count] = 'S';
                break;
                
            case 81:
                text[count] = 'E';
                break;
                
            case 82:
                text[count] = 'G';
                break;
                
            case 83:
                text[count] = 'J';
                break;
                
            case 84:
                text[count] = 'F';
                break;
                
            case 85:
                text[count] = 'H';
                break;
                
            case 86:
                text[count] = 'B';
                break;
                
            case 87:
                text[count] = 'P';
                break;
                
            case 88:
                text[count] = 'N';
                break;
                
            case 89:
                text[count] = 'K';
                break;
                
            case 90:
                text[count] = 'C';
                break;
                
            default:
                text[count] = text[count];
                break;
        }
        count++;
    } while (text[count] != 0);
    
    printf("Encoded text is: %s\n", text);
}

//---------------------------------------------------------------------------------------------------------------

void substitutionDecryption()
{
    char text[51]; //Encrypted text
    int count = 0;
    
    printf("Please enter encrypted text to be decrypted:\n");
    scanf(" %[^\n]%*c", text);
    
    //Plain Text: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    //Encrypted:  DTIOXZMQAWLRVUYSEGJFHBPNKC
    
    do
    {
        if (text[count] >= 97 && text[count] <= 122)
        {
            text[count] -= 32;
        }
        switch (text[count])
        {
            case 65:
                text[count] = 'I';
                break;
            
            case 66:
                text[count] = 'V';
                break;
                
            case 67:
                text[count] = 'Z';
                break;
            
            case 68:
                text[count] = 'A';
                break;
            
            case 69:
                text[count] = 'Q';
                break;
            
            case 70:
                text[count] = 'T';
                break;
                
            case 71:
                text[count] = 'R';
                break;
                
            case 72:
                text[count] = 'U';
                break;
                
            case 73:
                text[count] = 'C';
                break;
                
            case 74:
                text[count] = 'S';
                break;
                
            case 75:
                text[count] = 'Y';
                break;
                
            case 76:
                text[count] = 'K';
                break;
                
            case 77:
                text[count] = 'G';
                break;
                
            case 78:
                text[count] = 'X';
                break;
                
            case 79:
                text[count] = 'D';
                break;
                
            case 80:
                text[count] = 'W';
                break;
                
            case 81:
                text[count] = 'H';
                break;
                
            case 82:
                text[count] = 'L';
                break;
                
            case 83:
                text[count] = 'P';
                break;
                
            case 84:
                text[count] = 'B';
                break;
                
            case 85:
                text[count] = 'N';
                break;
                
            case 86:
                text[count] = 'M';
                break;
                
            case 87:
                text[count] = 'J';
                break;
                
            case 88:
                text[count] = 'E';
                break;
                
            case 89:
                text[count] = 'O';
                break;
                
            case 90:
                text[count] = 'F';
                break;
                
            default:
                text[count] = text[count];
                break;
        }
        count++;
    } while (text[count] != 0);
    
    printf("Encoded text is: %s\n", text);
}


