#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



int writeCSVFile() {
    FILE *fpt;
    // Open a new file "accounts.csv" in write mode. 
    // "w+" creates a new file or overwrites an existing one.
    fpt = fopen("seven_cs_database.csv", "w+");

    // Write the header row
    fprintf(fpt, "ID, Name, Password, Bankroll\n");

    // Example data to write (usually this would be in a loop or array)
    int id = 1;
    char name[] = "John asdf";
    char email[] = "john@example.com";
    char phone[] = "555-1234";

    // Write a data row, using commas as delimiters and '\n' for a new row
    fprintf(fpt, "%d, %s, %s, %s\n", id, name, email, phone);

    // Close the file
    fclose(fpt);

    return 0;
}

void load_test_data() {
    printf("Loading test data... \n");

    FILE *fpt;
    // Open a new file "accounts.csv" in write mode. 
    // "w+" creates a new file or overwrites an existing one.
    fpt = fopen("seven_cs_database.csv", "w+");

    // Write the header row
    fprintf(fpt, "ID, Name, Password, Bankroll\n");

    // Example data to write (usually this would be in a loop or array)
    int id_index = 1;
    char *name[4] = {"Freddie", "Brian", "John", "Roger"};
    char *password[4] = {"Password1", "Password2", "Password3", "Password4"};
    char *bankroll[4] = {"1000", "900", "1100", "1200"};

    for(int i=0; i<4; i++) {
        // Write a data row, using commas as delimiters and '\n' for a new row
        fprintf(fpt, "%d, %s, %s, %s\n", id_index, name[i], password[i], bankroll[i]);
        id_index++;
    }
    // Write a data row, using commas as delimiters and '\n' for a new row
    // fprintf(fpt, "%d, %s, %s, %s\n", id_index, name[0], password[0], bankroll[0]);

    // Close the file
    fclose(fpt);

    printf("Test data loaded successfully! \n");

}




#define MAXCHAR 1000

int readCSVFile() {
    FILE *fp;
    char row[MAXCHAR];
    char* token;

    // Open the file in read mode
    fp = fopen("seven_cs_database.csv", "r");

    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    // Read each line until the end of the file
    while (feof(fp) != true) {
        fgets(row, MAXCHAR, fp);
        
        // Use strtok to parse the row with a comma delimiter
        token = strtok(row, ",");
        while (token != NULL) {
            printf("%s ", token);
            // Get the next token
            token = strtok(NULL, ",");
        }
        printf("--\n"); // Newline for each new row
    }

    // Close the file
    fclose(fp);

    return 0;
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* trim_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // If all spaces
    if (*str == '\0') {
        return str;
    }

    // Find end of string
    end = str + strlen(str) - 1;

    // Trim trailing space
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Write new null terminator
    *(end + 1) = '\0';

    return str;
}



int load_user(char *name) {
    printf("Loading user data... \n");



    char *password = "Password3";

    FILE *fp;
    char row[MAXCHAR];
    char *token;

    fp = fopen("seven_cs_database.csv", "r");

    if (fp == NULL) {
        printf("Could not open file\n");
        exit(0);
    }

    int col = 0;


    while (fgets(row, MAXCHAR, fp) != NULL) {
        col = 0;
        row[strcspn(row, "\n")] = '\0';
        token = strtok(row, ",");

        while (token != NULL) {
            // printf("%s - ", token);

            // if(col == 3 && row != 0) {
            //     int num = atoi(token);
            
            //     printf("as int: %d\n", num);
            // }

            

            if(col == 1) {
                char* trimmed_token = trim_whitespace(token);
                
                if(strcmp(trimmed_token, name) == 0) {
                    printf("MATCH\n");
                    printf("%s\n", row);

                    for(int i=0; i<20; i++) {
                        printf("%c\n", row[i]);
                    }
                    exit(0);
                }
            }

            token = strtok(NULL, ",");
            col += 1;
        }
        printf("\n");
    }

    fclose(fp);



    return 0;
}



int create_user(char *name) {
    printf("Creating new user... \n");
    return 0;
}


int test() {
    return 1;
}

void get_user_data(char **name, int *bankroll) {


    
    if( (*bankroll = load_user(*name)) != -1) {
        printf("User exists! \n");
    } else {
        printf("User does not exist! \n");
        create_user(*name);
    }


    // int a;

    // if((a = test()) == 2) {
    //     printf("a;lskdfj\n");
    // }


    // *name = "Tyler";
    // *bankroll = 123;

    
}


int main() {

    char name[] = "Freddie";
    char *trimmed_name = trim_whitespace(name);
    char *password = "Password3";
    // writeCSVFile();
    load_test_data();

    // readCSVFile();

    // char *name;
    int bankroll;

    get_user_data(&trimmed_name, &bankroll);

    

    
    printf("User: %s, Bankroll: %d\n", name, bankroll);

    return 0;
}
