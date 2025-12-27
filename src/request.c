#include <request.h>
#include <string.h>
int parse_request(char *request, struct request *req) {
    char *method, *url, *version, *headers, *body;
    char *request_line = strtok(request, "\r\n");
    if (request_line == NULL) {
        return -1;
    }
    char buffer[1024];
    strcpy(buffer, request_line);

    return 0;
}
void devide_request_line(char *request_line, char **method, char **url, char **version) {
    char *token = strtok(request_line, " ");
    if (token == NULL) {
        return;
    }
    *method = token;
    token = strtok(NULL, " ");
    if (token == NULL) {
        return;
    }
    *url = token;
    token = strtok(NULL, " ");
    if (token == NULL) {
        return;
    }
    *version = token;
    return 0;
    
}