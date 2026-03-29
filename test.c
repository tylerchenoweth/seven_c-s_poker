#include <stdio.h>
#include <string.h>

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define MAX_LENGTH 10


bool get_new_hand() {

    while(1) {
        char str[] = "asdf 134 ";   // +1 for null terminator

        // char str[10];
        // printf("Enter a string (max 10 characters): \n> ");
        // get_string_input(str, sizeof(str));

        printf("Main has: %s\n", str);

        // remove non numbers from string
        remove_all_non_nums(str);

        if(str == NULL) {
            printf("You didnt enter any valid numbers\n");
        }

        
        printf(">>>%s<<<\n", str);



        bool new_cards_bool[5] = {false, false, false, false, false};

        printf("String Length = %ld\n", strlen(str));

        if(str[0] == '0') {
            for(int i=0; i<5; i++) {
                new_cards_bool[i] = true;
            }
        } else { 
            for(int i=0; i<strlen(str); i++) {
                int index = str[i] - '0';
                new_cards_bool[index-1] = true;
            }
        }

        for(int i=0; i<5; i++) {
            printf("%d\n", new_cards_bool[i]);
        }

        exit(0);

        if(!strcmp(str, "9")) {
            printf("You didnt enter any valid numbers\n");
        } else {
            return new_cards_bool;
        }

        


        printf("\n\n\n");
    }
}



void remove_all_non_nums(char *str) {
    int i = 0, j = 0;
    bool has_zero = false;
    bool has_nums = false;

    // check for 0
    while(str[i]) {
        if(str[i] == '0') {
            printf("Has zero is true\n");
            has_zero = true;
        }
        i++;
    }


    i=0;

    while (str[i]) {
        if (!isspace((unsigned char)str[i]) && is_in_range(str[i], '0', '5')) {
            if(has_zero == true && is_in_range(str[i], '1', '5')) {
                printf("> You cannot have a 0 and numbers 1-5.\nTry Again\n");
                str[0] = '9';
                str[1] = '\0';
                // return str;
                return;
            }
            printf("++++++++\n");
            has_nums = true;
            str[j++] = str[i];
        } 
        
        i++;
    }
    str[j++] = '\0';

    if(has_nums == false && has_zero == false) {
        printf("> You didnt enter a 0 or 1-5\n");
        str[0] = '9';
        str[1] = '\0';
        // return str;
        return;
    } 

    // return str;
    return;
}









bool is_in_range(char c, char min, char max) {
    return (c >= min && c <= max);
}


// Function takes a buffer and its size
void get_string_input(char *buffer, int buffer_size) {
    if (fgets(buffer, buffer_size, stdin) != NULL) {
        // Remove newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        
        printf("You entered: %s\n", buffer);
    } else {
        printf("Error reading input.\n");
    }
}


bool* redraw() {

    // allocate memory for bool arr
    bool* new_cards_bool = (bool*)malloc(5 * sizeof(bool));

    if (new_cards_bool == NULL) {
        // Handle allocation failure
        return NULL;
    }

    bool valid_input = false;

    do {
        char new_hand_input[10];
        bool has_zero = false;
        bool has_nums = false;
        valid_input = true;

        // load bool array as all false
        for (int i = 0; i < 5; i++) {
            new_cards_bool[i] = false;
        }
        
        printf("Please use only spaces and numbers 1-5 OR a single 0.\n");
        printf("Enter a string (max 10 characters): \n> ");
        get_string_input(new_hand_input, sizeof(new_hand_input));
        
        for(int i=0; i<strlen(new_hand_input); i++) {
            if(is_in_range(new_hand_input[i], '1','5')) {
                if(has_zero == true) {
                    printf("Invalid input. You entered a 0 and a number(s) between 1-5...\n");
                    valid_input = false;
                } else {
                    has_nums = true;
                }
            } else if(new_hand_input[i] == '0') {
                if(has_nums == true) {
                    printf("Invalid input. You entered a 0 and a number(s) between 1-5...\n");
                    valid_input = false;
                } else {
                    has_zero = true;
                }
            } else {
                if(new_hand_input[i] != ' ') {
                    printf("Invalid character\n");
                    valid_input = false;
                }
            }
        }

        if(has_zero == true && has_nums == false) {
            for (int i = 0; i < 5; i++) {
                new_cards_bool[i] = true;
            }
        } else if(valid_input == true) {
            for(int i=0; i<strlen(new_hand_input); i++) {
                if(new_hand_input[i] == ' ') {
                    continue;
                } else {
                    int index = new_hand_input[i] - '0';
                    index -= 1;
                    if(new_cards_bool[index] == 1) {
                        printf("> You entered duplicate inputs... %d\n", new_cards_bool[index]);
                        valid_input = false;
                    } else {
                        new_cards_bool[index] = true;
                    }
                }
            }  
        }   
    } while(valid_input == false);

    return new_cards_bool;
}


int main() {
    bool *cards = redraw();

    for(int i=0; i<5; i++) {
        printf("%d\n", cards[i]);
    }
    printf("\n\n\n");

    return 0;
}















// #include <stdio.h>
// #include <stdbool.h>

// bool is_in_range(char c, char min, char max) {
//     return (c >= min && c <= max);
// }

// int main() {
//     char my_char = 'C';

//     if (is_in_range(my_char, 'A', 'Z')) {
//         printf("The character %c is in the range A-Z.\n", my_char);
//     } else {
//         printf("The character %c is not in the range A-Z.\n", my_char);
//     }

//     // Example with digits '0'-'9'
//     char digit_char = '5';
//     if (is_in_range(digit_char, '0', '9')) {
//         printf("The character %c is a digit.\n", digit_char);
//     }

//     return 0;
// }
