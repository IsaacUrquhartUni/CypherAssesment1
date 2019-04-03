#include<stdio.h>
//sxdfcgvhbjnkm
int main(void) 
{
    void rotationEncryption();
    char option;
    
    option = 'a'; //Add scanf() before finishing project.
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
    
    //scanf() to go here for menu selection
        
    //----------------------------------------------------------------------------------------
    /*Runs the corresponding program based on the user input, and also returns an error message
      if the user inputs an invalid option.                                                    */ 
    
    switch (option)
    {
        case 97:
            rotationEncryption();
            break;
        
        default: 
            printf("ERROR: Enter a valid menu option");
            break;
    }
    
    //----------------------------------------------------------------------------------------
    
    return 0;
}

void rotationEncryption()
{
    char text[50];
    
    printf("Please enter some text to be encoded (Max 50 characters):\n");
    for (int index = 0; index < 50; index++)
    {
            scanf("%c", text[index]);
    }
   
    for (int index = 0; index < 50; index++)
    {
            printf("%c", text[index]);
    }
}




