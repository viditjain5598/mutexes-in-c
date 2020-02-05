#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *first_entry_point(void *value) {
    printf("hello from the second thread :)\n");

    int *num = (int *) value;

    printf("the value of value is %d\n", *num);

    return NULL;
}

void *second_entry_point(void *value){
    printf("Hello from the third thread!\n");
    int *num = (int*) value;
    printf("%d\n", *num);
    return NULL;    
}

int main(int argc, char **argv) {
    pthread_t thread1;
    pthread_t thread2;

    printf("hello from the first thread :D\n");

    int num1 = 123, num2 = 456;

    pthread_create(&thread1, NULL, first_entry_point, &num1);
    pthread_create(&thread2, NULL, second_entry_point, &num2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("That's all Folks!!\n");

    return EXIT_SUCCESS;
}
