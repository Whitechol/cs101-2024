#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    FILE* fp;
    long pos;
    
    int a[] = {0, 1, 2};
    char b[] = "abc";
    float c[] = {1.1, 1.2, 1.3};
    
    int ra[sizeof(a)/4];
    char rb[sizeof(b)];
    float rc[sizeof(c)/4];
    
    fp = fopen("a.bin", "wb+");
    fwrite(a, sizeof(a), 1, fp);
    fwrite(b, sizeof(b), 1, fp);
    fwrite(c, sizeof(c), 1, fp);
    
    fseek(fp, 0, SEEK_SET);
    fread(ra, sizeof(ra), 1, fp);
    
    fseek(fp, sizeof(ra)/4 * sizeof(int), SEEK_SET);
    fread(rb, sizeof(rb), 1, fp);
    
    fseek(fp, sizeof(ra)/4 * sizeof(int) + sizeof(rb) * sizeof(char), SEEK_SET);
    fread(rc, sizeof(rc), 1, fp);
    
    fclose(fp);
    
    for (int i=0; i<3; i++)
    {
        printf("%d ", ra[i]);
    }
    printf("\n");
    
    for (int i=0; i<3; i++)
    {
        printf("%c ", rb[i]);
    }
    printf("\n");
    
    for (int i=0; i<3; i++)
    {
        printf("%.1f ", rc[i]);
    }

    return 0;
}
