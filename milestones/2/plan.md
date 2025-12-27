# 🟩 Milestone 2 — HTTP Parsing (Minimal)

**Goal:** understand HTTP, not fully implement it.

## 🤔 Why Do We Need HTTP Requests?

### The Problem with Milestone 1

In **Milestone 1**, you built a TCP server that:
- Accepts connections
- Reads raw bytes
- Sends back `"Hello World"` (always the same thing)

**But what if the client wants:**
- `/index.html` instead of `/about.html`?
- To POST data instead of GET?
- To know what type of content you're sending?
- To send authentication?

**Raw TCP can't tell you any of this!** TCP just gives you a stream of bytes with no meaning.

### HTTP Solves This

**HTTP (HyperText Transfer Protocol)** is a **standardized format** that structures the conversation:

```
Client sends:                    Server understands:
─────────────────────────────────────────────────────
GET /index.html HTTP/1.1    →   "I want to GET /index.html"
Host: localhost:8080         →   "For this host"
                                "Using HTTP version 1.1"
```

### What HTTP Requests Give Us

1. **Method** (`GET`, `POST`, `PUT`, `DELETE`) - What action does the client want?
2. **Path** (`/index.html`, `/api/users`) - What resource are they asking for?
3. **Headers** - Metadata (authentication, content type, cookies, etc.)
4. **Body** (optional) - Data to send (for POST/PUT)

### Real Example

When you type `http://localhost:8080/index.html` in a browser, it sends:

```
GET /index.html HTTP/1.1
Host: localhost:8080
User-Agent: Mozilla/5.0...
Accept: text/html,application/xhtml+xml
```

Without HTTP parsing, your server sees just raw bytes and can't understand:
- What file the user wants
- What browser they're using
- What content types they accept

**That's why we need to parse HTTP requests!**

## Implement

```c
struct http_request {
    char method[8];
    char path[256];
};
```

## Tasks

- Parse request line:
    
    ```
    GET /index.html HTTP/1.1
    
    ```
    
- Ignore headers (for now)
- Reject non-GET methods

## Output

- Correct method & path extraction

