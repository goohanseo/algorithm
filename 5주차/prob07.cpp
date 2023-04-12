#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LEN 1024
#define MAX_RECORDS 100000

typedef struct {
    char ip[16];
    time_t time;
    char url[MAX_LINE_LEN];
    int status;
} Record;

int cmp_time(const void *a, const void *b) {
    Record *r1 = (Record *)a;
    Record *r2 = (Record *)b;
    return difftime(r1->time, r2->time);
}

int cmp_ip(const void *a, const void *b) {
    Record *r1 = (Record *)a;
    Record *r2 = (Record *)b;
    int cmp = strcmp(r1->ip, r2->ip);
    if (cmp != 0) {
        return cmp;
    }
    return cmp_time(a, b);
}

int main() {
    Record records[MAX_RECORDS];
    int n = 0;
    FILE *fp = fopen("/Users/guhanseo/c++/5주차/webLog.csv", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        char *ip = strtok(line, ",");
        char *time_str = strtok(NULL, ",");
        char *url = strtok(NULL, ",");
        char *status_str = strtok(NULL, ",");
        struct tm time_info;
        strptime(time_str, "%d/%b/%Y:%H:%M:%S", &time_info);
        time_t time = mktime(&time_info);
        if (time == (time_t)-1) {
            fprintf(stderr, "Failed to parse time: %s", time_str);
            continue;
        }
        int status = atoi(status_str);
        if (n < MAX_RECORDS) {
            strncpy(records[n].ip, ip, sizeof(records[n].ip));
            records[n].time = time;
            strncpy(records[n].url, url, sizeof(records[n].url));
            records[n].status = status;
            n++;
        } else {
            fprintf(stderr, "Max number of records reached");
            break;
        }
    }
    fclose(fp);

    qsort(records, n, sizeof(Record), cmp_time);
    for (int i = 0; i < n; i++) {
        char time_str[MAX_LINE_LEN];
        strftime(time_str, sizeof(time_str), "%d/%b/%Y:%H:%M:%S", localtime(&records[i].time));
        printf("%s IP: %s URL: %s Status: %d\n", time_str, records[i].ip, records[i].url, records[i].status);
    }

    qsort(records, n, sizeof(Record), cmp_ip);
    for (int i = 0; i < n; i++) {
        char time_str[MAX_LINE_LEN];
        strftime(time_str, sizeof(time_str), "%d/%b/%Y:%H:%M:%S", localtime(&records[i].time));
        printf("%s Time: %s URL: %s Status: %d\n", records[i].ip, time_str, records[i].url, records[i].status);
    }

    return 0;
}
