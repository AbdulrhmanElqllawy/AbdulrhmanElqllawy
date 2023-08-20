// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>



// int main(void){
    
// return 0;
// }

#include <stdio.h>

int main()
{   
    // array to store string taken as input
    char sentence[20];
    
    // take user input
    printf("Enter any sentence: ");
    
    // use scanf to take input
    scanf("%[^5]s", sentence);
    
    // printing the input value
    printf("You entered: %s.", sentence);
    
    return 0;
}