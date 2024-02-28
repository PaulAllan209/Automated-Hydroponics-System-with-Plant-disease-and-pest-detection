#include <iostream>
#include <string>    
#include <string.h>

// char char_test[] = "<1,2,3,4>";
// char delimiter[] = ",";
// char *ptr_delim = &delimiter;
static bool new_data = false;
char received_dat[10];

int main(){
    // char *portion1 = strtok(char_test, delimiter);

    // printf("%s\n", portion1);

    // std::cout << tester[0];
    return 0;
}


void data_parse(char (&data)[10]){
    static int ndx{0};
    char start_marker{'<'};
    char end_marker{'>'};
    int data1;
    int data2;
    int data3;
    static bool curr_at_start = false;
    char group_dat[20];
    
    // system for parsing data in each
    for (char i : data){
        if (i!=end_marker){
            if (i==start_marker){
                curr_at_start = true;
            }
        }
    }
}

void data_parser(char* data){

}