# Understanding HTTP: Why We Need It

## Visual Comparison

### Milestone 1: Raw TCP (No HTTP)

```
Client sends:           Server receives:
─────────────────────────────────────────
"Hello Server!"    →    Just bytes: 
                        [72, 101, 108, 108, 111, ...]
                        
                        ❌ Server has NO IDEA:
                        - What the client wants
                        - What file to serve
                        - What action to perform
                        
                        Server just responds:
                        "Hello World" (always the same)
```

### Milestone 2: HTTP Protocol

```
Client sends:                    Server receives & parses:
────────────────────────────────────────────────────────────
GET /index.html HTTP/1.1    →   Method: GET
Host: localhost:8080         →   Path: /index.html
User-Agent: curl/7.68.0      →   Version: HTTP/1.1
                                Headers: Host, User-Agent
                                
                                ✅ Server KNOWS:
                                - Client wants to GET
                                - They want /index.html
                                - Can route to correct file
                                - Can send proper response
```

## The HTTP Request Structure

```
┌─────────────────────────────────────────┐
│  Request Line (what you're parsing)     │
│  GET /index.html HTTP/1.1               │
├─────────────────────────────────────────┤
│  Headers (metadata)                     │
│  Host: localhost:8080                   │
│  User-Agent: Mozilla/5.0...             │
│  Accept: text/html                      │
├─────────────────────────────────────────┤
│  Body (optional, for POST/PUT)          │
│  (empty for GET requests)               │
└─────────────────────────────────────────┘
```

## Why Parse the Request Line?

The **request line** (`GET /index.html HTTP/1.1`) tells you:

1. **Method** (`GET`) → What action?
   - `GET` = "Give me this resource"
   - `POST` = "Here's data, process it"
   - `PUT` = "Update this resource"
   - `DELETE` = "Remove this resource"

2. **Path** (`/index.html`) → What resource?
   - `/index.html` → serve `www/index.html`
   - `/about.html` → serve `www/about.html`
   - `/api/users` → call API handler

3. **Version** (`HTTP/1.1`) → Which protocol version?
   - Tells you what features are available
   - HTTP/1.1 supports persistent connections

## Real-World Analogy

Think of it like ordering at a restaurant:

**Without HTTP (Milestone 1):**
- Customer: "Hello!"
- Waiter: "Here's a burger" (always the same)

**With HTTP (Milestone 2):**
- Customer: "I'd like a burger, please" (structured request)
- Waiter: "Got it! One burger coming up" (understands what you want)

## What You'll Build

In this milestone, you'll extract:
```c
struct http_request {
    char method[8];    // "GET", "POST", etc.
    char path[256];   // "/index.html", "/about.html", etc.
};
```

This lets your server:
- ✅ Know which file to serve
- ✅ Reject invalid methods (e.g., POST when you only support GET)
- ✅ Route different paths to different handlers (later milestones)

