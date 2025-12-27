# 🟩 Milestone 3 — Response Builder

**Goal:** generate valid HTTP responses.

## Implement

```c
void send_response(int fd, int status, const char *body);
```

## Handle

- `200 OK`
- `404 Not Found`
- Proper headers
- Correct `Content-Length`

