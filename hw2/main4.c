#include <stdio.h>
#include <string.h>

typedef struct book_list
{
    int id;
    int price;
    char title[128];
} book_list_t;

void total_price(book_list_t books[])
{
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += books[i].price;
    }
    printf("%d\n", sum);
}

void list_book(book_list_t books[], int n)
{
    printf("%d %s\n", books[n].price, books[n].title);
}
int main()
{
    book_list_t books[6];
    int n;
    
    scanf("%d", &n);
    
    books[0].id = 1;
    books[0].price = 1000;
    strcpy(books[0].title, "All the Light We Cannot See");
    
    books[1].id = 2;
    books[1].price = 300;
    strcpy(books[1].title, "The 38 Letters from J.D. Rockefeller to his son");
    
    books[2].id = 2;
    books[2].price = 1000;
    strcpy(books[2].title, "The Ballad of Songbirds and Snakes");
    
    books[3].id = 4;
    books[3].price = 550;
    strcpy(books[3].title, "Killers of the Flower Moon");
    
    books[4].id = 5;
    books[4].price = 870;
    strcpy(books[4].title, "Elon Musk");
    
    books[5].id = 6;
    books[5].price = 1344;
    strcpy(books[5].title, "Milk and Honey 12-Month 2024");
    
    if(n == 0) {
        total_price(books);
    }
    else{
        list_book(books, n - 1);
    }
    
    return 0;
}