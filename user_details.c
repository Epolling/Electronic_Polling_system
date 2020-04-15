//header files
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void user_details(char* name)
{
    FILE* fp;
    char buf[1024];
    int row = 0, col = 0;
    printf("\n==========================================");
    printf("\nUSER INFORMATION");
    fp = fopen("userdetails.csv", "r");
    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }
    while (fgets(buf, 1024, fp))
    {
        col = 0;
        row++;

        if (row == 1) {
            continue;
        }
        char* field = strtok(buf, ",");
        printf("\n");
        char* string = field;
        string = strtok(NULL, ",");
        //printf("%s", field);
        if (strcmp(field, name) == 0)
        {
            while (field)
            {
                if (col == 0) {
                    printf("First Name:\t");
                }
                if (col == 1) {
                    printf("Last Name:\t");
                    printf("%s\n", string);
                    col++;
                }
                if (col == 2) {
                    printf("Age:\t");
                }
                if (col == 3) {
                    printf("Phone:\t");
                }
                if (col == 4) {
                    printf("Postal code:\t");
                }
                if (col == 5) {
                    printf("Province:\t");
                    printf("%s\n", field);
                    candidate_details(field);
                    break;

                }
                if (col < 5 && col != 1) {
                    printf("%s\n", field);
                    field = strtok(NULL, ",");
                    col++;
                }
            }
            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}