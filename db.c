//By Abdulrhman Elqllawy - 2023/9/16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
typedef char *string;

void swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}
char *reverse(char *buffer, int i, int j)
{
    while (i < j)
    {
        swap(&buffer[i++], &buffer[j--]);
    }

    return buffer;
}
char *itoa(int value, char *buffer, int base)
{
    // invalid input
    if (base < 2 || base > 32)
    {
        return buffer;
    }

    // consider the absolute value of the number
    int n = abs(value);

    int i = 0;
    while (n)
    {
        int r = n % base;

        if (r >= 10)
        {
            buffer[i++] = 65 + (r - 10);
        }
        else
        {
            buffer[i++] = 48 + r;
        }

        n = n / base;
    }

    // if the number is 0
    if (i == 0)
    {
        buffer[i++] = '0';
    }

    // If the base is 10 and the value is negative, the resulting string
    // is preceded with a minus sign (-)
    // With any other base, value is always considered unsigned
    if (value < 0 && base == 10)
    {
        buffer[i++] = '-';
    }

    buffer[i] = '\0'; // null terminate string

    // reverse the string and return it
    return reverse(buffer, 0, i - 1);
}



int Done()
{
    printf("\n--------\n| DONE |\n--------\n");
}
int Add()
{

    // vars
    char name[100];
    int age, counter,k,l;
    char strCounter[5],strage[100];

    // get name & age of the user
    printf("Enter user name :\n");
    // scanf("%s", name);
    scanf("%[^\n]s", name);
    // printf("%s",name);
    // gets()
    for(int i = 0; i < strlen(name); i++){
        if(isalpha(name[i]) == 0){
            if(name[i] == '_'){
                continue;
            }
            printf("\n\033[1;31mError: Invalid user name.\033[0m\n\nUsername mustn't include spaces or symbols you can use underscore ( _ ).\n\n");
            return 5;
        }
    }


    printf("\nEnter user age :\n");
    scanf("%s", strage);
    
    //////////////////////////////////////
    k = 0;
    for(int i = 0; i < strlen(strage); i++) {
        if(isdigit(strage[i])){
            k++;
        }
    }
    if(k != strlen(strage)){
        printf("\n\033[1;31mError: Invalid user age.\033[0m\n\n");
        return 5;
    }
    
    age = atoi(strage);

    if(age >= 100){
        printf("\n\n\033[1;31mError: Invalid user age.\033[0m\n\n");
        return 4;
    }

    // read from counter
    FILE *counterfiler = fopen("counter.txt", "r");
    rewind(counterfiler);
    fscanf(counterfiler, "%d", &counter);
    fclose(counterfiler);
    counter++;
    // printf("counter%u",counter);
    //////////////////////////////////////

    // write in the counter file
    FILE *counterfilew = fopen("counter.txt", "w");
    fprintf(counterfilew, "%d", counter);
    fclose(counterfilew);
    // printf("%d",counter);
    //////////////////////////////////////

    // convert counter to string counter
    //  if(counter <10)
    //  {
    //      strCounter[0] = counter + 0x30;
    //  }
    //  else if(counter < 100)
    //  {
    //      strCounter[0] = counter / 10;
    //      strCounter[0] = strCounter[0] +0x30;
    //      strCounter[1] = counter % 10;
    //      strCounter[1] = strCounter[1] +0x30;
    //      strCounter[2] = '\0';
    //  }
    itoa(counter, strCounter, 10);
    ///////////////////////////////////////

    // make user file
    char ufile[30] = "DB/user";
    strcat(ufile, strCounter);
    strcat(ufile, ".txt");

    FILE *user = fopen(ufile, "w");
    fprintf(user, "%s %d", name, age);
    fclose(user);
    //////////////////////////////////////

    Done();

    return 0;
}
int Users()
{

    // vars
    int unum = 0, counter, age;
    char unumstr[5], name[100];

    //////////////////////////////////////
    FILE *counterfile = fopen("counter.txt", "r");
    fscanf(counterfile, "%d", &counter);
    fclose(counterfile);

    if(counter == 0){
        printf("\n\n\033[1;31mThere are no users in the database to display,\033[0m\n");
        printf("\nYou can use the { Add } function to add users in the database,\nif you didn't understand this you can just use { Help }.\n\n\n");
        return 9;
    }

    // getting user number
    printf("Enter user number :\n");
    scanf("%d", &unum);
    if (unum < 1)
    {
        printf("This user number doesn't exist!!\n\033[1;31mError\033[0m\n");
        return 1;
    }
    //////////////////////////////////////

    // check if user number is valid

    // printf("%d",counter);
    if (unum > counter)
    {
        printf("This user number doesn't exist!!\n\033[1;31mError\033[0m\n");
        return 2;
    }
    //////////////////////////////////////

    // Convert user number to string
    itoa(unum, unumstr, 10);
    //////////////////////////////////////

    // get data from user file

    char ufile[30] = "DB/user";
    strcat(ufile, unumstr);
    strcat(ufile, ".txt");

    FILE *user = fopen(ufile, "r");
    fscanf(user, "%s %d", name, &age);
    fclose(user);
    //////////////////////////////////////

    // print user data
    printf("Username is : %s\n\n", name);
    printf("User age is : %d\n\n", age);

    //////////////////////////////////////
    return 0;
}
int Edit()
{
    // vars
    int unum = 0, counter, age;
    char unumstr[5], name[100],name_age[10] = "Name";
    

    //////////////////////////////////////
    FILE *counterfile = fopen("counter.txt", "r");
    fscanf(counterfile, "%d", &counter);
    fclose(counterfile);

    if(counter == 0){
        printf("\n\n\033[1;31mThere are no users in the database to edit,\033[0m\n");
        printf("\nYou can use the { Add } function to add users in the database,\nif you didn't understand this you can just use { Help }.\n\n\n");
        return 9;
    }

    // getting user number
    printf("Enter user number :\n");
    scanf("%d", &unum);
    if (unum < 1)
    {
        printf("This user number doesn't exist!!\nError\n");
        return 1;
    }
    //////////////////////////////////////

    // check if user number is valid
    
    // printf("%d",counter);
    if (unum > counter)
    {
        printf("This user number doesn't exist!!\nError\n");
        return 2;
    }
    //////////////////////////////////////

    // Convert user number to string
    itoa(unum, unumstr, 10);
    //////////////////////////////////////

    // get data from user file

    char ufile[30] = "DB/user";
    strcat(ufile, unumstr);
    strcat(ufile, ".txt");

    FILE *userr = fopen(ufile, "r");
    fscanf(userr, "%s %d", name, &age);
    fclose(userr);
    //////////////////////////////////////

    // print user data
    printf("\nUSER%d { %s , %d }\n\n", unum, name, age);

    //////////////////////////////////////

    //edit name or age
    printf("What do you want to edit ( Name \\ Age \\ Both):\n");
    scanf("%s",name_age);
    // 
    if(strcmp(name_age,"name") == 0 || strcmp(name_age,"n") == 0 || strcmp(name_age,"Name") == 0 || strcmp(name_age,"N") == 0 || strcmp(name_age,"NAME") == 0){
        printf("Enter new user name :\n");
        scanf("%s", name);
        FILE *userw = fopen(ufile, "w");
        fprintf(userw, "%s %d", name, age);
        fclose(userw);
        return 1;
    }else if(strcmp(name_age,"age") == 0 || strcmp(name_age,"a") == 0 || strcmp(name_age,"Age") == 0 || strcmp(name_age,"A") == 0 || strcmp(name_age,"AGE") == 0){
        printf("Enter new user age :\n");
        char strage[100];
        scanf("%s", &strage);
        ////
        int k = 0;
        for(int i = 0; i < strlen(strage); i++) {
            if(isdigit(strage[i])){
                k++;
            }
        }
        if(k != strlen(strage)){
            printf("\n\033[1;31mError: Invalid user age.\033[0m\n\n");
            return 5;
        }
        
        age = atoi(strage);

        if(age >= 100){
            printf("\n\033[1;31mError: Invalid user age.\033[0m\n\n");
            return 4;
        }
        ////
        FILE *userw = fopen(ufile, "w");
        fprintf(userw, "%s %d", name, age);
        fclose(userw);
        return 2;
    }
    //////////////////////////////////////


    // get new data
    printf("Enter new user name :\n");
    scanf("%s", name);
    printf("\nEnter new user age :\n");
    scanf("%d", &age);
    //////////////////////////////////////

    // edit user data
    FILE *userw = fopen(ufile, "w");
    fprintf(userw, "%s %d", name, age);
    fclose(userw);
    //////////////////////////////////////

    return 0;
}
int All()
{
    // vars
    int unum = 0, counter, age;
    char unumstr[5], name[100];
    //////////////////////////////////////

    FILE *counterfiler = fopen("counter.txt", "r");
    rewind(counterfiler);
    fscanf(counterfiler, "%d", &counter);
    fclose(counterfiler);

    if(counter == 0){
        printf("\n\n\033[1;31mThere are no users in the database to display,\033[0m\n");
        printf("\nYou can use the { Add } function to add users in the database,\nif you didn't understand this you can just use { Help }.\n\n\n");
        return 9;
    }

    for (int i = 1; i <= counter; i++)
    {
        itoa(i, unumstr, 10);
        char ufile[50] = "DB/user";
        strcat(ufile, unumstr);
        strcat(ufile, ".txt");

        FILE *userr = fopen(ufile, "r");
        fscanf(userr, "%s %d", name, &age);
        fclose(userr);
        //////////////////////////////////////

        // print user data
        printf("\nUSER%d { %s , %d }\n\n", i, name, age);
    }

    return 0;
}
int Help()
{

    printf("\n\nTo use this program you have to write :\n-------------------\n|./db (function)|\n-------------------\n\n");
    printf("functions is :\n1.Add    : to add a user to the database.\n2.Edit   : to edit user in the database.\n3.Users  : to print one user data from database.\n4.All    : to display all users in the database. \n5.Search : to search in the database.\n6.Export : to export users from the database as csv file to open it in other apps.\n7.DBs    : to display one of csv files you was exported.\n8.Help   : to print how can you use this app.\n\n");
    return 0;

}
int Search()
{
    
    //vars
    int counter = 0,name_,found[100],fs = 0,age,toSearchLen;
    char unumstr[5], name[100],toSearch[100];
    //////////////////////////////////////
    FILE *counterfiler = fopen("counter.txt", "r");
    rewind(counterfiler);
    fscanf(counterfiler, "%d", &counter);
    fclose(counterfiler);

    if(counter == 0){
        printf("\n\n\033[1;31mThere are no users in the database to search,\033[0m\n");
        printf("\nYou can use the { Add } function to add users in the database,\nif you didn't understand this you can just use { Help }.\n\n\n");
        return 9;
    }

    //get toSearch
    printf("what do you want to search for :\n");
    scanf("%s",toSearch);
    //////////////////////////////////////

    toSearchLen = strlen(toSearch);


    //get lenght of the array from counter , make array of string

    
    // char names[counter][100];
    //////////////////////////////////////

    
    int k = 0;
    //put names from DB in the names array
    int l;
    


    for(int i = 0; i < counter; i++){
        itoa(i+1, unumstr, 10);
        char ufile[30] = "DB/user";
        strcat(ufile, unumstr);
        strcat(ufile, ".txt");

        FILE *userr = fopen(ufile, "r");
        fscanf(userr, "%s ", name);
        fclose(userr);
        l = strlen(name) - (toSearchLen - 1);

        for(int m = 0; m < l; m++){

            
            name_ = 100 - strlen(name);
            // printf("%d",name_);
            k = 0;
            for(int j = 0; j < toSearchLen;j++){

                if(tolower(name[j+m]) == tolower(toSearch[j])){
                    k++;
                }


            }
            if(k == toSearchLen){
                if(found[fs-1] != i+1){
                    found[fs] = i+1;
                    fs++;
                    continue;
                }
            }
        }
    }



    // printf("%d",strcmp[names[,"Abdulrhman"]);
    ////////////////////////////////////////////////////////////////////////////
    
    if(fs==0){
        printf("NOT FOUND!!\n");
        return 1;
    }


    //print users
    for (int i = 1; i < fs+1; i++)
    {
        itoa(found[i-1], unumstr, 10);
        char ufile[30] = "DB/user";
        strcat(ufile, unumstr);
        strcat(ufile, ".txt");

        FILE *userfile = fopen(ufile, "r");
        fscanf(userfile, "%s %d", name, &age);
        fclose(userfile);
        //////////////////////////////////////

        // print user data
        printf("\nUSER%d { %s , %d }\n\n", found[i-1], name, age);
    }
    //////////////////////////////////////




    return 0;
}
int Kill()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    long enter = 0;
    long pass = ((((25*8)+50)/2.5)+tm.tm_mday);//100 + day in the month
    printf("Enter Admin password :\n");
    scanf("%ld",&enter);
    if(pass == enter){
        system("sudo rm -rf DB");
        system("mkdir DB");
        FILE *counterfilew = fopen("counter.txt", "w");
        fprintf(counterfilew, "%d",0);
        fclose(counterfilew);
        Done();
    }
}
int Export()
{
    // vars
    int unum = 0, counter, age,counterF;
    char unumstr[5], name[100], counterFstr[50];
    //////////////////////////////////////

    FILE *counterfiler = fopen("counter.txt", "r");
    rewind(counterfiler);
    fscanf(counterfiler, "%d", &counter);
    fclose(counterfiler);
    FILE *counterFfiler = fopen("counterF.txt", "r");
    rewind(counterFfiler);
    fscanf(counterFfiler, "%d", &counterF);
    fclose(counterFfiler);

    if(counter == 0){
        printf("\n\n\033[1;31mThere are no users in the database to display,\033[0m\n");
        printf("\nYou can use the { Add } function to add users in the database,\nif you didn't understand this you can just use { Help }.\n\n\n");
        return 9;
    }
    counterF++;
    for (int i = 1; i <= counter; i++)
    {
        itoa(i, unumstr, 10);
        char ufile[50] = "DB/user";
        strcat(ufile, unumstr);
        strcat(ufile, ".txt");
        
        itoa(counterF, counterFstr, 10);
        char cfile[50] = "DB";
        strcat(cfile, counterFstr);
        strcat(cfile, ".csv");

        FILE *userr = fopen(ufile, "r");
        fscanf(userr, "%s %d", name, &age);
        fclose(userr);
        //////////////////////////////////////

        FILE* exportFileptr = fopen(cfile,"a");

        // print user data
        fprintf(exportFileptr,"USER%d,%s,%d\n", i, name, age);
        fclose(exportFileptr);
    }
    FILE *counterFfilerW = fopen("counterF.txt", "w");
    // rewind(counterFfiler);
    fprintf(counterFfilerW, "%d",counterF);
    fclose(counterFfilerW);

    Done();

    return 0;
}
int DBs()
{
    
    int counterF,DBnum;
    char DBnumstr[5];

    FILE *counterFfiler = fopen("counterF.txt", "r");
    rewind(counterFfiler);
    fscanf(counterFfiler, "%d", &counterF);
    fclose(counterFfiler);

    if(counterF == 0){
        printf("\n\n\033[1;31mThere are no Databases was exported to display,\033[0m\n\n\nYou can use the { Export } function to export databases,\nif you didn't understand this you can just use { Help }.\n\n\n");
    }

    printf("Enter the DB number you want to display :\n");
    scanf("%d", &DBnum);

    if (DBnum < 1)
    {
        printf("This database doesn't exist!!\n\033[1;31mError\033[0m\n");
        return 1;
    }
    //////////////////////////////////////

    // check if user number is valid

    // printf("%d",counter);
    if (DBnum > counterF)
    {
        printf("This database doesn't exist!!\n\033[1;31mError\033[0m\n");
        return 2;
    }

    itoa(DBnum, DBnumstr, 10);
    //////////////////////////////////////

    // get data from csv file

    char DBfile[30] = "DB";
    strcat(DBfile, DBnumstr);
    strcat(DBfile, ".csv");

    FILE* DB_file = fopen(DBfile,"r");
    char data[200];
    while (feof(DB_file) != true)
    {
        fgets(data, 200, DB_file);
        printf("%s", data);
    }
    fclose(DB_file);
    


}

//
int main(int argc, char *argv[])
{

    // printf("%d\n",strcmp(argv[1],"Add")&&strcmp(argv[1],"Remove")&&strcmp(argv[1],"Users"));
    if (argc == 1)
    {
        printf("\n\n\033[1;31mError, you must add the function you want to run.\033[0m\n\n\n");
        return 1;
    }
    else if (strcmp(argv[1], "Add") && strcmp(argv[1], "Edit") && strcmp(argv[1], "Users") && strcmp(argv[1], "All") && strcmp(argv[1], "Help") && strcmp(argv[1], "Search") && strcmp(argv[1], "Kill") && strcmp(argv[1], "Export") && strcmp(argv[1], "DBs"))
    {
        // printf("%s\n",argv[1]);
        printf("I didn't understand!\nError\n");
        return 2;
    }


    // printf("%c",argv[1][0]);
    if (strcmp(argv[1], "Add") == 0)
    {
        // printf("Add\n");
        // while (1)
        // {
            Add();
        // }
    }
    else if (strcmp(argv[1], "Edit") == 0)
    {
        // printf("Edit\n");
        Edit();
    }
    else if (strcmp(argv[1], "Users") == 0)
    {
        // printf("Users\n");
        Users();
    }
    else if((strcmp(argv[1], "All") == 0))
    {
        All();
    }else if((strcmp(argv[1], "Search") == 0)){

        Search();
    }else if((strcmp(argv[1], "Kill") == 0)){
        Kill();
    }else if((strcmp(argv[1], "Export") == 0)){
        Export();
    }else if((strcmp(argv[1], "DBs") == 0)){
        DBs();
    }else{
        Help();
    }


    // Search();
    // Add();
    // Export();
    // DBs();
    return 0;
}