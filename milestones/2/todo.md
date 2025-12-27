# Milestone 2 - Todo List

## Tasks

- [ ] **Create http_request struct**
  - Create a header file (e.g., `include/http.h`)
  - Define struct with `method[8]` and `path[256]` fields

- [ ] **Create function to read HTTP request**
  - Read from client socket until `\r\n\r\n` or newline
  - Store the raw request string in a buffer

- [ ] **Create function to parse request line**
  - Function name: `parse_request_line` (or similar)
  - Takes a string like `"GET /index.html HTTP/1.1"`
  - Extracts method and path from the request line

- [ ] **Implement parsing logic**
  - Split the request line by spaces
  - Extract method (first token)
  - Extract path (second token)
  - Ignore HTTP version (third token) for now

- [ ] **Add method validation**
  - Reject requests that are not GET method
  - Return error or set a flag for non-GET methods

- [ ] **Update main.c to read HTTP request**
  - Replace direct response sending
  - Read the HTTP request from `client_fd` first

- [ ] **Update main.c to parse request**
  - Call your parsing function
  - Extract and store method and path in the struct

- [ ] **Add error handling**
  - Handle malformed requests (missing method, path, or invalid format)
  - Return appropriate error responses

- [ ] **Test with curl or browser**
  - Test: `curl http://localhost:8000/index.html`
  - Verify that `method="GET"` and `path="/index.html"` are extracted correctly

- [ ] **Test rejection of non-GET methods**
  - Test: `curl -X POST http://localhost:8000/index.html`
  - Should return appropriate error response (e.g., 405 Method Not Allowed)

## Notes

- Focus on parsing the request line only
- Headers can be ignored for now (just skip past them)
- The goal is to understand HTTP structure, not full implementation

