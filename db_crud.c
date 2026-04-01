#include "db_crud.h"

#define MAXCHAR 1000

void load_test_data() {
    // printf("Loading test data... \n");

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
    // printf("Loading user data...\n");

    // char *password = "Password3";

    FILE *fp;
    char row[MAXCHAR];
    char row_copy[MAXCHAR];
    char *token;

    fp = fopen("seven_cs_database.csv", "r");

    if (fp == NULL) {
        printf("Could not open file\n");
        exit(0);
    }

    while (fgets(row, MAXCHAR, fp) != NULL) {
        row[strcspn(row, "\n")] = '\0';

        strcpy(row_copy, row);

        int col = 0;
        token = strtok(row, ",");

        while (token != NULL) {
            if (col == 1) {
                char *trimmed_token = trim_whitespace(token);

                int col_2 = 0;
                // if match
                if (strcmp(trimmed_token, name) == 0) {
                    char *token_1 = strtok(row_copy, ",");

                    while (token_1 != NULL) {
                        // printf("%d) Value: %s\n", col_2, trim_whitespace(token_1));
                        if(col_2 == 3) {
                            // bankroll = atoi(token_1);
                            fclose(fp);
                            // printf(">>>>>%d<<<<<",atoi(token_1));
                            return atoi(token_1);
                        }
                        token_1 = strtok(NULL, ",");
                        col_2++;
                    }

                    fclose(fp);
                    return 1;
                }
            }

            token = strtok(NULL, ",");
            col++;
        }
    }

    fclose(fp);
    return -1;
}


bool create_user(char *name) {
    // printf("Creating new user... \n");

    FILE *fpt;
    // Open a new file "accounts.csv" in write mode. 
    // "w+" creates a new file or overwrites an existing one.
    fpt = fopen("seven_cs_database.csv", "a");

    if(load_user(name) == -1) {
        // printf("Name is available\n");
        // Write a data row, using commas as delimiters and '\n' for a new row
        fprintf(fpt, "%d, %s, %s, %d\n", 5, name, "password5", 1000);
        // Close the file
        fclose(fpt);
        return true;
    } else {
        // Close the file
        fclose(fpt);
        return false;
    }
 
}


void get_user_data(char **name, int *bankroll) {
    if( (*bankroll = load_user(*name)) != -1) {
        // printf("\User exists! %ls\n", bankroll);
    } else {
        // printf("User does not exist! \n");
        bool userExists = false;
        while(userExists == false) {
            userExists = create_user(*name);
            // printf("*****%d\n\n", userExists);
        }
    }

    *bankroll = load_user(*name);
}



int update_bankroll(char *name, int new_money) {
    printf("Saving your new balance...\n");
    FILE *fp = fopen("seven_cs_database.csv", "r");
    FILE *temp = fopen("temp.csv", "w");

    char row[MAXCHAR];

    if (fp == NULL || temp == NULL) {
        printf("File error\n");
        return -1;
    }

    while (fgets(row, MAXCHAR, fp) != NULL) {
        char row_copy[MAXCHAR];
        strcpy(row_copy, row);

        row[strcspn(row, "\n")] = '\0';

        char *id = strtok(row, ",");
        char *user = strtok(NULL, ",");
        char *password = strtok(NULL, ",");
        char *money = strtok(NULL, ",");

        if (id && user && password && money) {
            user = trim_whitespace(user);

            if (strcmp(user, name) == 0) {
                fprintf(temp, "%s, %s, %s, %d\n",
                    trim_whitespace(id),
                    trim_whitespace(user),
                    trim_whitespace(password),
                    new_money
                );
            } else {
                fputs(row_copy, temp);
            }
        }
    }

    fclose(fp);
    fclose(temp);

    remove("seven_cs_database.csv");
    rename("temp.csv", "seven_cs_database.csv");

    return 1;
}


PlayerData db_main(void) {
    PlayerData player;

    printf("Enter your name: ");
    fgets(player.playerName, sizeof(player.playerName), stdin);

    char *trimmed = trim_whitespace(player.playerName);
    memmove(player.playerName, trimmed, strlen(trimmed) + 1);

    get_user_data(&trimmed, &player.bankroll);
    // update_bankroll(player.playerName, player.bankroll);

    return player;
}
