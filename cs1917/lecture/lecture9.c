#include <stdio.h>
#include <stdlib.h>

struct _books {
   int book_id;
   char title[50];
   char author[50];
};

struct _books creatbook();
void printfbook(struct _books book);

int main(int argc, char *argv[]){
   struct _books mybook = creatbook();
   printfbook(mybook);

   return EXIT_SUCCESS;
}

struct _books creatbook(){
   struct _books book;
   printf("enter the book id:");
   scanf("%d", &(book.book_id));
   printf("enter the book title:");
   scanf("%s", book.title);
   printf("enter the book author:");
   scanf("%s", book.author);

   return book;
}

void printfbook(struct _books book){
   printf("%d\n", book.book_id);
   printf("%s\n", book.title);
   printf("%s\n", book.author);


}
