#include <stdio.h>
#include <stdbool.h>

struct Date {
    int day, month, year;
};
struct Book {
    char cipher[20]; 
    char author[50]; 
    char title[100]; 
};
struct Reader {
    int card_number;  
    char last_name[50]; 
};
struct BookRequest {
    struct Book book;
    struct Reader reader;
    struct Date order_date;
};

int input_BookRequest(struct BookRequest *x) {
    printf("Шифр: "); scanf("%s", &(*x).book.cipher);
    printf("Автор: "); scanf("%s", &x->book.author);
    printf("Назва: "); scanf("%s", &x->book.title);
    printf("№ квитка: "); scanf("%d", &(*x).reader.card_number);
    printf("Прізвище: "); scanf("%s", &x->reader.last_name);
    printf("Введіть дату: ");
    scanf("%d %d %d", &(*x).order_date.day, &x->order_date.month, &x->order_date.year);
    return true;
}

void print_BookRequest(struct BookRequest x) {
    printf("Книга:[%s] %s - \"%s\"\n", x.book.cipher, x.book.author, x.book.title);
    printf("Читач:№%d, прізвище: %s\n", x.reader.card_number, x.reader.last_name);
    printf("Дата: %02d.%02d.%4d\n", x.order_date.day, x.order_date.month, x.order_date.year);
}

int main() {
    struct BookRequest request;
    if (input_BookRequest(&request)) {
        print_BookRequest(request);
    }
}