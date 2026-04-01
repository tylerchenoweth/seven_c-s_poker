#ifndef DB_CRUD_H
#define DB_CRUD_H

#include "constants.h"

#define MAXCHAR 1000

void load_test_data();
int readCSVFile();
char* trim_whitespace(char* str);
int load_user(char *name);
bool create_user(char *name);
void get_user_data(char **name, int *bankroll);
int update_bankroll(char *name, int new_money);
// char *db_main(void);

typedef struct {
    char playerName[50];
    int bankroll;
} PlayerData;

PlayerData db_main(void);


#endif