#include <stdio.h>
#include <string.h>
#define MAXC 31
#define MAX 1000

int readCommand(char command[MAXC]);

typedef struct {
    int y, m, d;
} date_t ;
date_t min_d = {.d=0, .m=0, .y=0}, max_d = {.d=0, .m=0, .y=0};

typedef struct {
    char code_route[MAXC], departure[MAXC], destination[MAXC], time_departure[MAXC], time_arrival[MAXC];
    date_t date;
    unsigned int delay;
} trip;

void printrip(trip trip_log);
void comparedates(date_t d1, date_t d2);

int main(int argc, char *argv[]) {
    if (argc != 2)
        return 1;
    FILE *fp;
    int i;
    char dep[MAXC], dest[MAXC], code[MAXC], command[MAXC];
    date_t d1, d2;
    char t1[MAXC], t2[MAXC], min_t[MAXC], max_t[MAXC];
    unsigned int nor, dly=0;
    trip trip_log[MAX];
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if (fscanf(fp, "%d", &nor) != 1) {
        printf("Error reading number of trips from file\n");
        fclose(fp);
        return 1;
    }
    for (i=0;i<nor;i++) {
        fscanf(fp, "%s %s %s %d/%d/%d %s %s %d",
               trip_log[i].code_route, trip_log[i].departure, trip_log[i].destination,
               &trip_log[i].date.y, &trip_log[i].date.m, &trip_log[i].date.d,
               trip_log[i].time_departure, trip_log[i].time_arrival, &trip_log[i].delay);
    }
    fclose(fp);
    printf("type <date> to list all rides departed within a certain interval of dates\n"
           "type <departure> to list all the trips starting from a given departure \n"
           "type <destination> to list all the trips with a given destination \n"
           "type <delay> to list all trips that reached their destination late, within a given interval of dates\n"
           "type <tot-delay> to list the overall delay accumulated by the trips that are identified by a given route code\n"
           "type <end> to terminate the program\n");
    scanf("%s", command);
    switch (readCommand(command)) {
        case 1:
            scanf("%d/%d/%d %d/%d/%d", &d1.y,&d1.m,&d1.d, &d2.y,&d2.m,&d2.d);
            comparedates(d1, d2);
            printf("\n%d %d %d - %d %d %d\n", max_d.y, max_d.m, max_d.d, min_d.y, min_d.m, min_d.d);
            for (i=0;i<nor;i++) {
                if ((trip_log[i].date.y*10000+trip_log[i].date.m*100+trip_log[i].date.d) <= (max_d.y*10000+max_d.m*100+max_d.d) && (trip_log[i].date.y*10000+trip_log[i].date.m*100+trip_log[i].date.d) >= (min_d.y*10000+min_d.m*100+min_d.d)) {
                    printrip(trip_log[i]);
                }
            }
            break;
        case 2:
            scanf("%s", dep);
            for (i=0;i<nor;i++) {
                if (strcmp(trip_log[i].departure, dep) == 0)
                    printrip(trip_log[i]);
            }
            break;
        case 3:
            scanf("%s", dest);
            for (i=0;i<nor;i++) {
                if (strcmp(trip_log[i].destination, dest) == 0)
                    printrip(trip_log[i]);
            }
            break;
        case 4:
            scanf("%s %s", t1, t2);
            if (strcmp(t1,t2)>0){
                strcpy(max_t, t1);
                strcpy(min_t, t2);
            }
            else {
                strcpy(max_t, t2);
                strcpy(min_t, t1);
            }
            for (i=0;i<nor;i++) {
                if (strcmp(trip_log[i].time_arrival, min_t) >= 0 && strcmp(trip_log[i].time_arrival, max_t) <= 0 && trip_log[i].delay > 0)
                    printrip(trip_log[i]);
            }
            break;
        case 5:
            scanf("%s", code);
            for (i=0;i<nor;i++) {
                if (strcmp(trip_log[i].code_route, code) == 0)
                    dly += trip_log[i].delay;
            }
            printf("overall delay: %d", dly);
            break;
        case 6:
            printf("program terminated upon request..");
            break;
        default:
            printf("not valid command, type one of these; <date> <departure> <destination> <delay> <tot-delay> <end>");
    }
    return 0;
}

void comparedates(date_t d1, date_t d2) {
    if (d1.y > d2.y) {
        max_d.y = d1.y; max_d.m = d1.m; max_d.d = d1.d;
        min_d.y = d2.y; min_d.m = d2.m; min_d.d= d2.d;
    }
    else if (d2.y > d1.y) {
        max_d.y = d2.y; max_d.m = d2.m; max_d.d = d2.d;
        min_d.y = d1.y; min_d.m = d1.m; min_d.d = d1.d;
    }
    else {
        if (d1.m > d2.m) {
            max_d.y = d1.y; max_d.m = d1.m; max_d.d = d1.d;
            min_d.y = d2.y; min_d.m = d2.m; min_d.d= d2.d;
        }
        else if (d2.m > d1.m) {
            max_d.y = d2.y; max_d.m = d2.m; max_d.d = d2.d;
            min_d.y = d1.y; min_d.m = d1.m; min_d.d = d1.d;
        }
        else {
            if (d1.d > d2.d) {
                max_d.y = d1.y; max_d.m = d1.m; max_d.d = d1.d;
                min_d.y = d2.y; min_d.m = d2.m; min_d.d= d2.d;
            }
            else if (d2.d > d1.d) {
                max_d.y = d2.y; max_d.m = d2.m; max_d.d = d2.d;
                min_d.y = d1.y; min_d.m = d1.m; min_d.d = d1.d;
            }
            else
                max_d.y = min_d.y = d2.y; max_d.m = min_d.m = d2.m; max_d.d = min_d.d = d2.d;
        }
    }
}

void printrip(trip trip_log) {
    printf("%s %s %s %d/%d/%d %s %s %d\n",
           trip_log.code_route, trip_log.departure, trip_log.destination,
           trip_log.date.y, trip_log.date.m, trip_log.date.d,
           trip_log.time_departure, trip_log.time_arrival,
           trip_log.delay);
}

int readCommand(char command[MAXC]) {
    int no;
    if (strcmp(command, "date") == 0)
        no = 1;
    else if (strcmp(command, "departure") == 0)
        no = 2;
    else if (strcmp(command, "destination") == 0)
        no = 3;
    else if (strcmp(command, "delay") == 0)
        no = 4;
    else if (strcmp(command, "tot-delay") == 0)
        no = 5;
    else if (strcmp(command, "end") == 0)
        no = 6;
    else
        return -1;
    return no;
}