#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp_in, *fp_out;
    char line[1000];
    int line_number = 0;
    int main_line_number = 0;
    fp_in = fopen("main3.c", "r");
    fp_out = fopen("main3.txt", "w");
    while (fgets(line, sizeof(line), fp_in) != NULL) {
        line_number++;
        if (strstr(line, "int main()") != NULL) {
            main_line_number = line_number;
            break;
        }
    }
    fprintf(fp_out, "%d", main_line_number);
    fclose(fp_in);
    fclose(fp_out);
    
    return 0;
}
