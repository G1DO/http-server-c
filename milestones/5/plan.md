# 🟩 Milestone 5 — Router

**Goal:** basic routing logic.

## Routes

- `/` → `index.html`
- `/health` → plain text
- `/echo` → returns request info

## Implement

```c
typedef void (*route_handler)(int client_fd);
```

