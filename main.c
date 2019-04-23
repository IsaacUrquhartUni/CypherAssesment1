#include<stdio.h>

int main(void) 
{
    
    void menu(); //Calls the menu function
    int exit;    //Variable for the option to exit the program
    
    /* This loop will run the program once, then at the end ask the user if they would like to exit.
     * If the user enters 1, the loop breaks and the program ends, otherwise it will start over again. */
    do 
    {
        menu();
        printf("\nExit? (1) Yes (2) No\n");
        scanf(" %i", &exit);
    } while (exit != 1);
       
    return 0;
}

//---------------------------------------------------------------------------------------------

void menu(void)
{
    void rotationEncryption();      //Declares rotationEncryption function.
    void rotationDecryption();      //Declares rotationDecryption function.
    void substitutionEncryption();  //Declares substitutionEncryption function.
    void substitutionDecryption();  //Declares substitutionDecryption function.
    char option = ' ';              //Sets / resets the variable option to a blank space (or 32 in ASCII).

    //Menu printed to screen: 
    printf("############################################################\n");
    printf("# Please select an option from the menu below:             #\n");
    printf("#                                                          #\n");
    printf("# (a) Rotation encryption      (b) Rotation decryption     #\n");
    printf("# (c) Substitution encryption  (d) Substitution decryption #\n");
    printf("#                                                          #\n");
    printf("############################################################\n");
    
    scanf(" %c", &option); //Reads users input and assigns the variable to 'option'.
    
    
    /* Runs the corresponding program based on the user input, and also returns an error message
     * if the user inputs an invalid option. */ 
    
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

/* Once this function is called it will ask the user for a text input, and after the user presses the enter key
 * it will then ask for a key. The key will shift the value of each character up the desired amount until all
 * the text is encrypted. */

void rotationEncryption()
{
    char text[51];  //An array to store the line of text, has a max length of 51 characters.
    int key = 0;    /* This variable is used to input the users desired amount of shifting the letters 
                     * should undergo. */
    int count = 0;  //A variable to act as a counter for how many times the loop has been completed.
    
    printf("Please enter some text to be encoded (Max 50 characters):\n");
    scanf(" %[^\n]%*c", text); /* The %[^\n] will ensure the input is read until right before a new line 
                                * is encountered, then the %*c will read the new line character then discard
                                * it afterward. */
    printf("\nEnter the key for encryption (Must be between 0 and 25):\n");
    scanf("\n %i", &key); //Inputs a single integer as the key and stores it in the 'key' variable.
    
    /* Runs a loop adding the key to the value of the current text[count], and ensures the result will always
     * be within (including) 65 and 90 in the ASCII table. */
    do
    {
        //If the original letter is between 'A' and 'Z' minus the key, it will simply have its value added.
        if (text[count] >= 65 && text[count] <= 90-key) 
        {
            text[count] += key;
        }
        
        /* If the original letter is between 'a' and 'z' minus the key, it will subtract 32 to reach the 
         * capital version of the letter then perform the addition of the key. */
        else if (text[count] >= 97 && text[count] <= 122-key)
        {
            text[count] += key-32;
        }
        
        /* If the original letter is between 'Z' minus the key and 'Z', the program will subract 26 to start
         * counting from the start of the capital alphabet, then add the key to the value of the char.*/
        else if (text[count] > 90-key && text[count] <= 90)
        {
            text[count] += key-26;
        }
        
        /* If the original letter is between 'z' minus the key and 'z',the program will subtract 32 to bring
         * the value back to the capital letters, then the program will subract 26 to start
         * counting from the start of the capital alphabet, then add the key to the value of the char.*/
        else if (text[count] > 122-key && text[count] <= 122)
        {
            text[count] += key-32-26;
        }
        
        //If the original character is not a letter, it will not shift the value.
        else
        {
            text[count] = text[count];
        }
        
        count++; //Increases the counter before ending the loop.
    } while (text[count] != 0); /* While the line has not finished with a null value 'char 0', the loop will
                                 * keep running. */
    
    printf("Encoded text is: %s\n", text); //Prints encrypted text.
    
}

//----------------------------------------------------------------------------------------------------

void rotationDecryption()
{
    char eText[51]; //Encrypted text array with a max length of 51 characters
    int key = 0;    /* This variable is used to input the users desired amount of shifting the letters 
                     * should undergo. */
    int count = 0;  //A variable to act as a counter for how many times the loop has been completed.
    
    printf("Please enter encrypted text to be decoded:\n");
    scanf(" %[^\n]%*c", eText);     /* The %[^\n] will ensure the input is read until right before a new line 
                                     * is encountered, then the %*c will read the new line character then discard
                                     * it afterward. */
    printf("Enter the decryption key:\n");
    scanf(" %i", &key); //Inputs a single integer as the key and stores it in the 'key' variable.
    
    /* Runs a loop subtracting the key from the value of the current text[count], and ensures the result will always
     * be within (including) 65 and 90 in the ASCII table. */
    do
    {
        /* If the original letter is between 'A' + the key and 'Z', the program will simply subract the key 
         * from the current eText[count]. */
        if (eText[count] >= 65+key && eText[count] <= 90)
        {
            eText[count] -= key;    
        }
        
        /* If the encrypted letter is between 'a' + the key and 'z', the program will subtract 32 from the char
         * value to bring it baack to the capital letters, then subtract the value of the key. */
        else if (eText[count] >= 97+key && eText[count] <= 122)
        {
            eText[count] += -key-32;
        }
        
        /* If the encrypted letter is between 'A' + the key and 'A', the program will add 26 to bring the value to the 
         * end of of teh capital alphabet, then subtract the key. */
        else if (eText[count] < 65+key && eText[count] >= 65)
        {
            eText[count] += -key+26;
        }
        
        /* If the encrypted letter is between 'a' and 'a' + the key, the program will -32 from the value to bring
         * the value back to the capital letters, it will then add 26 to bring the value to the end of the capital
         * alphabet, then it will subtract the key. */
        else if (eText[count] >= 97 && eText[count] < 97+key)
        {
            eText[count] += -key+26-32;
        }
        
        //If the character is not a letter, it will not change its value.
        else
        {
            eText[count] = eText[count];
        }
        
        count++; //Increases the count before the loop ends.
    } while (eText[count] != 0); /* While the line has not finished with a null value 'char 0', the loop will
                                  * keep running. */
    
    printf("Decrypted text is: %s\n", eText); //Prints the decrypted text.
}

//--------------------------------------------------------------------------------------------------------------

void substitutionEncryption()
{
    char text[51]; //Encrypted text array with a max length of 51 characters.
    int count = 0; //Counter variable for how many times 
    
    printf("Please enter text to be encrypted:\n");
    scanf(" %[^\n]%*c", text); /* The %[^\n] will ensure the input is read until right before a new line 
                                * is encountered, then the %*c will read the new line character then discard
                                * it afterward. */
    
    //Plain Text: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    //Encrypted:  DTIOXZMQAWLRVUYSEGJFHBPNKC
    
    /* This loop will make sure all characters are capital letters, otherwise it will convert them by subtracting
     * 32. Then it will run through and convert each letter to the coresponding substitution as outlined in the
     * comment above. */
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
        count++; //Increases the counter before the loop ends.
    } while (text[count] != 0); /* While the line has not finished with a null value 'char 0', the loop will
                                 * keep running. */
    
    printf("Encoded text is: %s\n", text); //Prints encrypted text.
}

//---------------------------------------------------------------------------------------------------------------

void substitutionDecryption()
{
    char text[51]; //Encrypted text
    int count = 0; //Counter variable for how many times
    
    printf("Please enter encrypted text to be decrypted:\n");
    scanf(" %[^\n]%*c", text); /*The %[^\n] will ensure the input is read until right before a new line 
                                * is encountered, then the %*c will read the new line character then discard
                                * it afterward. */
    
    //Plain Text: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    //Encrypted:  DTIOXZMQAWLRVUYSEGJFHBPNKC
    
    /* This loop will make sure all characters are capital letters, otherwise it will convert them by subtracting
     * 32. Then it will run through and convert each letter to the coresponding substitution as outlined in the
     * comment above. */
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
        count++; //Increases the counter before the loop ends.
    } while (text[count] != 0); /* While the line has not finished with a null value 'char 0', the loop will
                                 * keep running. */
    
    printf("Encoded text is: %s\n", text); //Prints decrypted text.
}


