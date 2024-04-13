#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char status[10];
    int *ptr[10];
    int ptr_head[10];
    int ptr_size[10];
} my_mm_t;

int g_mm[10];
my_mm_t mms;

void print_calloc_array(int flag) {
    if (flag == 0) {
        printf("%s <- Out of space\n", mms.status);
    }
    else {
        printf("%s\n", mms.status);
    }
}

int *my_calloc(int n, int size) {
    int count = 0, head = 0;
    for (int i = 0; i < 10; i++) {
        if (mms.status[i] == '0') {
            count++;
            if (count >= size)
                break;
        }
        else if (mms.status[i] == '1'){
            count = 0;
            head = i + 1;
        }
    }
    
    if (count < size) {
        print_calloc_array(0);
        return NULL;
    }
    
    for (int i = head; i < head + size; i++) {
            mms.status[i] = '1';
            g_mm[i] = n;
        }
    int *tmp = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < 10; i++) {
      if (mms.ptr[i] == NULL) {
        mms.ptr[i] = tmp;
        mms.ptr_head[i] = head;
        mms.ptr_size[i] = size;
        break;
      }
    }
    print_calloc_array(1);
    return tmp;
}

void my_free(int *p) {
    for (int i = 0; i < 10; i++) {
        if (mms.ptr[i] == p) {
            for (int j = mms.ptr_head[i]; j < mms.ptr_head[i] + mms.ptr_size[i]; j++) {
                mms.status[j] = '0';
                g_mm[j] = 0;
            }
            mms.ptr[i] = NULL;
            mms.ptr_head[i] = 0;
            mms.ptr_size[i] = 0;
            break;
        }
    }
    free(p);
    print_calloc_array(1);
}

int main()
{
    for (int i = 0; i < 10; i++)
        mms.status[i] = '0';
    int *np1 = my_calloc(1, 1);
    int *np2 = my_calloc(1, 2);
    int *np3 = my_calloc(1, 3);
    int *np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int *np5 = my_calloc(1, 5);
    int *np6 = my_calloc(1, 1);
    return 0;
}