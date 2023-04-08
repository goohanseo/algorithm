    // Read log file and parse each line into a LogEntry struct
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char* ip = strtok(line, ",");
        char* time = strtok(NULL, ",");
        char* url = strtok(NULL, ",");
        char* status = strtok(NULL, ",");
        if (ip && time && url && status) {
            LogEntry entry;
            strncpy(entry.ip, ip, MAX_IP_LENGTH);
            strncpy(entry.time, time, MAX_TIME_LENGTH);
            strncpy(entry.url, url, MAX_URL_LENGTH);
            strncpy(entry.status, status, MAX_STATUS_LENGTH);
            entries[num_entries++] = entry;
        }
    }
