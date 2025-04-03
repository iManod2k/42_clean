#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct args_s
{
    pthread_mutex_t tmutex;
    int             num;
} args_t;

void *routine_funct(void *arguments)
{
    int     cont = 0;
    args_t  *args = (args_t *) arguments;

    while (cont < 100000)
    {
        pthread_mutex_lock(&args->tmutex);
        args->num += 1;
        cont++;
        pthread_mutex_unlock(&args->tmutex);
    }
    printf("Soy thread %d\n", ((int) args->num) );
    (args->num)++;
    return (NULL);
}

int main(void)
{
    args_t *arguments = malloc(sizeof(args_t));
    (*arguments).num = 0;
    
    pthread_t       thread1, thread2;

    pthread_mutex_init(&(*arguments).tmutex, NULL);

    pthread_create(&thread1, NULL, routine_funct, (void *) arguments);
    pthread_create(&thread2, NULL, routine_funct, (void *) arguments);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&(*arguments).tmutex);
    
    free(arguments);

    return (EXIT_SUCCESS);
}