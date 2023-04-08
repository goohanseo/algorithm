#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_IP_LENGTH 16
#define MAX_TIME_LENGTH 32
#define MAX_URL_LENGTH 512
#define MAX_STATUS_LENGTH 8
#define MAX_LOG_ENTRIES 1000


typedef struct {
    char ip[MAX_IP_LENGTH];
    char time[MAX_TIME_LENGTH];
    char url[MAX_URL_LENGTH];
    char status[MAX_STATUS_LENGTH];
} LogEntry;

void print_entries(LogEntry* entries, int num_entries);
int compare_time(const void* a, const void* b);
int compare_ip(const void* a, const void* b);

int main() {
        printf("hello");

    FILE* fp;
    char line[MAX_LINE_LENGTH];
    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
        printf("hello");

    fp = fopen("/Users/guhanseo/c++/5주차/webLog.csv", "r");
    printf("hello");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open log file\n");
        exit(1);
    }

    // Read log file and parse each line into a LogEntry struct
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    char* ip = strtok(line, ",");
    char* time = strtok(NULL, ",");
    char* url = strtok(NULL, ",");
    char* status = strtok(NULL, ",");
    if (ip && time && url && status) {
        LogEntry entry;
        strlcpy(entry.ip, ip, MAX_IP_LENGTH);
        strlcpy(entry.time, time, MAX_TIME_LENGTH);
        strlcpy(entry.url, url, MAX_URL_LENGTH);
        strlcpy(entry.status, status, MAX_STATUS_LENGTH);
        entries[num_entries++] = entry;
    }
}


    // Sort log entries based on user's choice of sorting criteria
    char cmd[MAX_LINE_LENGTH];
   while (1) {
    printf("Enter command (sort -t, sort -ip, print, or exit): ");
    fgets(cmd, MAX_LINE_LENGTH, stdin);
    if (strcmp(cmd, "sort -t\n") == 0) {
        qsort(entries, num_entries, sizeof(LogEntry), compare_time);
        printf("Log entries sorted in chronological order\n");
    } else if (strcmp(cmd, "sort -ip\n") == 0) {
        qsort(entries, num_entries, sizeof(LogEntry), compare_ip);
        printf("Log entries sorted by IP address\n");
    } else if (strcmp(cmd, "print\n") == 0) {
        print_entries(entries, num_entries);
    } else if (strcmp(cmd, "exit\n") == 0) {
        break;
    } else {
        printf("Invalid command. Please try again.\n");
    }
}

    fclose(fp);
    return 0;
}

int compare_time(const void* a, const void* b) {
    LogEntry* entry1 = (LogEntry*)a;
    LogEntry* entry2 = (LogEntry*)b;
    return strcmp(entry1->time, entry2->time);
}

int compare_ip(const void* a, const void* b) {
    LogEntry* entry1 = (LogEntry*)a;
    LogEntry* entry2 = (LogEntry*)b;
    int cmp = strcmp(entry1->ip, entry2->ip);
    if (cmp == 0) {
        cmp = compare_time(a, b);
    }
    return cmp;
}

void print_entries(LogEntry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("IP: %s\nTime: %s\nURL: %s\nStatus: %s\n\n", 
                entries[i].ip, entries[i].time, entries[i].url, entries[i].status);
    }
}
