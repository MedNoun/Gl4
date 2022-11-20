#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
// 0 1 2  3 4 5
// A B C  D E F
// 0 1 2 -1 3 4

typedef struct station{
    char name;
    struct station* next;
    pthread_mutex_t lock;
}station;

typedef struct{
    char name;
    station origine;
    station* current;
    station destination;
}train;

pthread_mutex_t mutex[100];

void* mv_station_next(void* in){
    train* t;
    t = (train*)in;

    while(t->current->name != t->destination.name){
        station* o = t->current;
        pthread_mutex_lock(&(o->lock));
        t->current = t->current->next;
        if(t->current){
            printf("\n%c going to %c",t->name, t->current->name);
            fflush(stdout);
        }
        usleep(6000000);
        pthread_mutex_unlock(&(o->lock));
    }
    printf("\n%c finished ! ", t->name);
    fflush(stdout);
}

void* init_train(train* trains,int len,pthread_mutex_t* mutex, station* stations){
    for(int i = 0; i<len; i++){

        char c = i + 65;
        trains[i].name = c;
        int index;
        printf("Origine: ");
        fflush(stdout);
        scanf("%d", &index);
        trains[i].origine = stations[index];
        trains[i].current = &(trains[i].origine);
        int index2;
        printf("Destination: ");
        fflush(stdin);
        scanf("%d", &index2);
        trains[i].destination = stations[index2];
    }
    
}

void* init_stations(station* stations,int len){
    for(int i = 0 ; i<len ; i++){
        char c;
        printf("Station Name : ");
        fflush(stdout);
        scanf(" %c",&c);
        stations[i].name = c;

        int index;
        printf("Mutex Index: ");
        fflush(stdout);
        scanf("%d", &index);

        int index2;
        printf("Next Station Index: ");
        fflush(stdout);
        scanf("%d", &index2);

        if(index == -1){
            stations[i].next = NULL;
        }else{
            stations[i].next = &(stations[index2]);
            pthread_mutex_init(&mutex[index], NULL);
            stations[i].lock = mutex[index];
        }

        
        
        
    }
    
}

int main(){
    int num_stations;
    int num_trains;
    int sem;
    printf("Stations : ");
    scanf("%d", &num_stations);
    printf("Trains : ");
    scanf("%d",&num_trains);
    printf("Mutex : ");
    scanf("%d",&sem);
    station stations[num_stations];
    train trains[num_trains];
    pthread_t threads[num_trains];
    init_stations(stations,num_stations);
    init_train(trains,num_trains, mutex, stations);
    for(int i = 0; i<num_trains; i++){
        pthread_create(&threads[i], NULL,mv_station_next,(void *)&trains[i]);
        printf("\ncreated %d",i);
    }

    for(int j = 0; j<num_trains; ++j){
        pthread_join(threads[j], NULL);
    }
    
}