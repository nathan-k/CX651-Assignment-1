#include "mini.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test_sort() {
    unsigned long long x = sort(120);
    unsigned long long y = sort(-120);
    unsigned long long z = sort(3);
    unsigned long long a = sort(5);

    return x == 11 && y == 17 && z == 17 && a == 11;
}

int test_sort2() {
    unsigned long long x = sort(120);
    unsigned long long y = sort(-120);
    unsigned long long z = sort(3);
    unsigned long long a = sort(5);

    printf("%llu %llu %llu %llu\n", x,y,z,a);
    return x == 11 && y == 17 && z == 17 && a == 17;
}

int test_branch() {
    unsigned long long x = branch(11, 10);
    unsigned long long y = branch(4,5);
    unsigned long long z = branch(1,1);

     printf("%llu %llu %llu\n", x,y,z);
    return x == 1 && y == 12 && z == 33;
}

int test_loop() {
    unsigned long long x = loop(3,2);
    unsigned long long y = loop(5,10);
    unsigned long long z = loop(3,5);

    printf("%llu %llu %llu\n", x,y,z);

    return x == 8 && y == 130 && z == 26;
}

int run_test(char * test_name, int (*test_func)()) {
    int test_res = test_func();
    printf("%-25s: %d/1\n", test_name, test_res);
    return test_res;
}

int main(int argc, char **argv){
    if(argc != 2) {
        printf("ERROR: expected format ./test_one <test_num | ALL>\n");
        return -1;
    }
    int passed = 0;
    int test_num = -1;
    if(strcmp(argv[1],"ALL") != 0) {
        test_num = atoi(argv[1]);
    }
    
    char *test_list[] = {"Test Sort","Test Branch", "Test Loop", "Test Sort 2"};
    int (*test_func[])() = {&test_sort, &test_branch, &test_loop, &test_sort2};
    
    int tests_ran = 0;
    if(test_num != -1) {
        passed += run_test(test_list[test_num], test_func[test_num]);
        tests_ran += 1;
    } else {
        for(int i = 0; i < 4; i++) {
            passed += run_test(test_list[i], test_func[i]);
            tests_ran += 1;
        }
    }

    printf("Total: %d/%d\n", passed, tests_ran);
    return passed;
}