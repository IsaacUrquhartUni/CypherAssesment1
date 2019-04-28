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
    void unknownRotateDecrypt();    //Declares unknownRotateDecrypt function.
    char option = ' ';              //Sets / resets the variable option to a blank space (or 32 in ASCII).

    //Menu printed to screen: 
    printf("#############################################################\n");
    printf("# Please select an option from the menu below:              #\n");
    printf("#                                                           #\n");
    printf("# (a) Rotation encryption      (b) Rotation decryption      #\n");
    printf("# (c) Substitution encryption  (d) Substitution decryption  #\n");
    printf("# (e) Unknown rotation decryption                           #\n");
    printf("# (f) Unknown substitution decryption (Not yet implemented) #\n");
    printf("#                                                           #\n");
    printf("#############################################################\n");
    
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
        
        case 101:
            unknownRotateDecrypt();
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
    char text[2000] = " ";  //An array to store the line of text, has a max length of 2000 characters.
    int key = 0;    /* This variable is used to input the users desired amount of shifting the letters 
                     * should undergo. */
    int count = 0;  //A variable to act as a counter for how many times the loop has been completed.
    
    printf("Please enter some text to be encoded:\n");
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
    char eText[2000] = " "; //Encrypted text array with a max length of 2000 characters
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
    char text[2000] = " "; //Encrypted text array with a max length of 2000 characters.
    int count = 0; //Counter variable for how many times 
    char key[26]; //Char array to store the alphabetical key
    
    printf("Please enter text to be encrypted:\n");
    scanf(" %[^\n]%*c", text); /* The %[^\n] will ensure the input is read until right before a new line 
                                * is encountered, then the %*c will read the new line character then discard
                                * it afterward. */
    
    printf("Please enter a 26 character alphabetical key:");
    scanf(" %[^\n]%*c", key);  //Enters a 26 character length key into the 'key' array
    
    
    do
    {
        //The following if statement converts each character in the text to its capital form.
        if (text[count] >= 97 && text[count] <= 122)
        {
            text[count] -= 32;
        }
        
        //The switch statement assigns characters to their respective substitutions according to the position.
        switch (text[count])
        {
            case 65:
                text[count] = key[0];
                break;
            
            case 66:
                text[count] = key[1];
                break;
                
            case 67:
                text[count] = key[2];
                break;
            
            case 68:
                text[count] = key[3];
                break;
            
            case 69:
                text[count] = key[4];
                break;
            
            case 70:
                text[count] = key[5];
                break;
                
            case 71:
                text[count] = key[6];
                break;
                
            case 72:
                text[count] = key[7];
                break;
                
            case 73:
                text[count] = key[8];
                break;
                
            case 74:
                text[count] = key[9];
                break;
                
            case 75:
                text[count] = key[10];
                break;
                
            case 76:
                text[count] = key[11];
                break;
                
            case 77:
                text[count] = key[12];
                break;
                
            case 78:
                text[count] = key[13];
                break;
                
            case 79:
                text[count] = key[14];
                break;
                
            case 80:
                text[count] = key[15];
                break;
                
            case 81:
                text[count] = key[16];
                break;
                
            case 82:
                text[count] = key[17];
                break;
                
            case 83:
                text[count] = key[18];
                break;
                
            case 84:
                text[count] = key[19];
                break;
                
            case 85:
                text[count] = key[20];
                break;
                
            case 86:
                text[count] = key[21];
                break;
                
            case 87:
                text[count] = key[22];
                break;
                
            case 88:
                text[count] = key[23];
                break;
                
            case 89:
                text[count] = key[24];
                break;
                
            case 90:
                text[count] = key[25];
                break;
                
            default:
                text[count] = text[count];
                break;
        }
        count++; //Increases the counter before the loop ends.
    } while (text[count] != 0); /* While the line has not finished with a null value 'char 0', the loop will
                                 * keep running. */
    count = 0;
    
    do 
    //Converts all characters in the text to uppercase.
    {
        if (text[count] >= 97 && text[count] <= 122)
        {
            text[count] -= 32;
        }
        count++;
    } while (text[count] != 0);
    
    
    
    printf("Encoded text is: %s\n", text); //Prints encrypted text.
}

//---------------------------------------------------------------------------------------------------------------

void substitutionDecryption()
{
    char text[2000] = " "; //Encrypted text
    char key[26];
    
    int count = 0; //Counter variable for how many times
    int counter = 0; //counter for the inner loop
    
    printf("Please enter encrypted text to be decrypted:\n");
    scanf(" %[^\n]%*c", text); /*The %[^\n] will ensure the input is read until right before a new line 
                                * is encountered, then the %*c will read the new line character then discard
                                * it afterward. */
    printf("Please enter a 26 character alphabetical key:");
    scanf(" %[^\n]%*c", key); //Used to enter the decryption key
    
    do 
    //Converts all characters in the text to uppercase.
    {
        if (text[count] >= 97 && text[count] <= 122)
        {
            text[count] -= 32;
        }
        count++;
    } while (text[count] != 0);
    
    count = 0;
    
    do 
    //Converts all characters in the key to uppercase.
    {
        if (key[count] >= 97 && key[count] <= 122)
        {
            key[count] -= 32;
        }
        count++;
    } while (key[count] != 0);
    
    count = 0;
    
    
    do
    //This loop will cycle through each character in the encrypted text.
    {
        do
        //This loop will cycle through all the key characters performing swaps when required.
        {
            /* If the current text character matches the current key character, the text character is swapped
             * with the position value of the key character plus 65. This will set the text character to the
             * current position of the key relative to the alphabet in the ASCII table. */
            if (text[count] == key[counter])
            {
                text[count] = counter + 65;
                break;
            }
            
            counter++;
        } while (key[counter] != 0);
        count++;
        counter = 0;
    } while(text[count] != 0);
    
    
    
    printf("Encoded text is: %s\n", text); //Prints decrypted text.
}

//------------------------------------------------------------------------------------------------------------

void unknownRotateDecrypt()
{
    char text[2000] = " ";  //An array to store the line of text, has a max length of 2000 characters.
    int key = 0;    /* This variable is used to input the users desired amount of shifting the letters 
                     * should undergo. */
    int count = 0;  //A variable to act as a counter for how many times the loop has been completed.
    int count1 = 1;  /* A variable to act as a counter for how many times the loop has been completed.
                      * Starting at 1 to start the loop on the second character. */
    
    printf("Please enter some text to be decoded:\n");
    scanf(" %[^\n]%*c", text); /* The %[^\n] will ensure the input is read until right before a new line 
                                * is encountered, then the %*c will read the new line character then discard
                                * it afterward. */
    
    do
    {
        //The following searches for the keyword "the".
        if ((text[count1-1] - text[count1] == 12 && text[count1] - text[count1+1] == 3) ||
            (text[count1-1] - text[count1] == 12 && text[count1] - text[count1+1] + 26 == 3) ||
            (text[count1-1] - text[count1] + 26 == 12 && text[count1] - text[count1+1] == 3) ||
            (text[count1-1] - text[count1] + 26 == 12 && text[count1] - text[count1+1] + 26 == 3))
        {
            if (text[count1] >= 65 && text[count1] <= 90)
            {
                if (text[count1] - 72 < 0)
                {
                    key = text[count1] -72 + 26;
                }else 
                {
                    key = text[count1] - 72; 
                }
            }else
            {
                text[count1] -= 32;
                if (text[count1] - 72 < 0)
                {
                    key = text[count1] -72 + 26;
                }else 
                {
                    key = text[count1] - 72; 
                }
            }  
        }
        
        //The following searches for the keyword "and".
        else if ((text[count1] - text[count1-1] == 13 && text[count1] - text[count1+1] == 10) ||
            (text[count1] - text[count1-1] == 13 && text[count1] + 26 - text[count1+1] == 10) ||
            (text[count1] + 26 - text[count1-1] == 13 && text[count1] - text[count1+1] == 10) ||
            (text[count1] + 26 - text[count1-1] == 13 && text[count1] + 26 - text[count1+1] == 10))
        {
            if (text[count1] >= 65 && text[count1] <= 90)
            {
                if (text[count1] - 78 < 0)
                {
                    key = text[count1] -78 + 26;
                }else 
                {
                    key = text[count1] - 78; 
                }
            }else
            {
                text[count1] -= 32;
                if (text[count1] - 78 < 0)
                {
                    key = text[count1] -78 + 26;
                }else 
                {
                    key = text[count1] - 78; 
                }
            }  
        }
        
        //The following searches for the keyword "to".
        else if ((text[count1-1] == 32 && text[count1+2] == 32) && ((text[count1] - text[count1+1] == 5) ||
                 (text[count1] + 26 - text[count1+1] == 5)))
        {
            if (text[count1] >= 65 && text[count1] <= 90)
            {
                if (text[count1] - 84 < 0)
                {
                    key = text[count1] - 84 +26;
                }else
                {
                    key = text[count1] - 84;
                }
            }else 
            {
                text[count1] -= 32;
                if (text[count1] - 84 < 0)
                {
                    key = text[count1] - 84 +26;
                }else
                {
                    key = text[count1] - 84;
                }
            }
        }
        //The following searches for the keyword "be".
        else if ((text[count1-1] == 32 && text[count1+2] == 32) && ((text[count1+1] - text[count1] == 3) ||
                 (text[count1+1] - text[count1] + 26 == 3)))
        {
            if (text[count1] >= 65 && text[count1] <= 90)
            {
                if (text[count1] - 66 < 0)
                {
                    key = text[count1] - 66 +26;
                }else
                {
                    key = text[count1] - 66;
                }
            }else 
            {
                text[count1] -= 32;
                if (text[count1] - 66 < 0)
                {
                    key = text[count1] - 66 +26;
                }else
                {
                    key = text[count1] - 66;
                }
            }
        }
        //The following searches for the keyword "of".
        else if ((text[count1-1] == 32 && text[count1+2] == 32) && ((text[count1] - text[count1+1] == 9) ||
                 (text[count1] + 26 - text[count1+1] == 9)))
        {
            if (text[count1] >= 65 && text[count1] <= 90)
            {
                if (text[count1] - 79 < 0)
                {
                    key = text[count1] - 79 +26;
                }else
                {
                    key = text[count1] - 79;
                }
            }else 
            {
                text[count1] -= 32;
                if (text[count1] -79 < 0)
                {
                    key = text[count1] - 79 +26;
                }else
                {
                    key = text[count1] - 79;
                }
            }
        }
        
        
        
        
        count1++;
    } while (count1 < 2000);
    printf("\nKey = %i\n", key);
    
    /* Runs a loop subtracting the key from the value of the current text[count], and ensures the result will always
     * be within (including) 65 and 90 in the ASCII table. */
    do
    {
        /* If the original letter is between 'A' + the key and 'Z', the program will simply subract the key 
         * from the current eText[count]. */
        if (text[count] >= 65+key && text[count] <= 90)
        {
            text[count] -= key;    
        }
        
        /* If the encrypted letter is between 'a' + the key and 'z', the program will subtract 32 from the char
         * value to bring it baack to the capital letters, then subtract the value of the key. */
        else if (text[count] >= 97+key && text[count] <= 122)
        {
            text[count] += -key-32;
        }
        
        /* If the encrypted letter is between 'A' + the key and 'A', the program will add 26 to bring the value to the 
         * end of of teh capital alphabet, then subtract the key. */
        else if (text[count] < 65+key && text[count] >= 65)
        {
            text[count] += -key+26;
        }
        
        /* If the encrypted letter is between 'a' and 'a' + the key, the program will -32 from the value to bring
         * the value back to the capital letters, it will then add 26 to bring the value to the end of the capital
         * alphabet, then it will subtract the key. */
        else if (text[count] >= 97 && text[count] < 97+key)
        {
            text[count] += -key+26-32;
        }
        
        //If the character is not a letter, it will not change its value.
        else
        {
            text[count] = text[count];
        }
        
        count++; //Increases the count before the loop ends.
    } while (text[count] != 0); /* While the line has not finished with a null value 'char 0', the loop will
                                  * keep running. */
    
    printf("Decrypted text is: %s\n", text); //Prints the decrypted text.
}
