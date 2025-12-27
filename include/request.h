struct request {
    char *method;
    char *url;
    char *version;
    char *headers;
    char *body;
};

int parse_request(char *request, struct request *req);
