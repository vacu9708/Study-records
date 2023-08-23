# Rate limiting
Rate limiting is a technique used to control the amount of incoming requests to a system.<br>
The token bucket algorithm is a common method to implement rate limiting.

## Token Bucket Algorithm
The Token Bucket algorithm allows for a burst of requests up to a maximum (the bucket size), and then refills the bucket with tokens at a steady rate.

### Step-by-step implementation
1. `Define the rate limit:` Choose the number of requests allowed in a given time window (e.g., 10 requests per second).
2. `Create a Redis key for Each Client:` Use a unique key for each client you want to rate limit (e.g., based on IP address or user ID).
3. `Use a Redis hash to store the tokens:` For each client, store two values in a hash:
    - **tokens:** The current number of tokens (requests) available.
    - **timestamp:** The last time the token bucket was updated.

4. `On Each Request:`
- Retrieve the tokens and timestamp for the client.
- Calculate the number of tokens to add based on the elapsed time since the last update.
- If there are enough tokens for the request, subtract one and update the tokens and timestamp.
- If there are not enough tokens, reject the request.

Use Redis Transactions if necessary: To ensure that the rate limiting is atomic and consistent, use Redis transactions (e.g., MULTI and EXEC commands).

### A code snippet in Python to illustrate the above steps
~~~python
import time
from collections import defaultdict

def rate_limit(client_id, replenish_rate, burst_capacity):
    current_time = time.time()
    # Retrieve the client's rate limit info from the dictionary
    client_info = rate_limit_buckets[client_id]

    tokens = client_info['tokens']
    timestamp = client_info['timestamp']

    # Calculate the number of tokens to add based on the elapsed time since the last update
    time_passed = current_time - timestamp # in seconds
    tokens += time_passed * replenish_rate
    # Cap the number of tokens at the burst capacity
    if tokens > burst_capacity:
        tokens = burst_capacity
    # Not enough tokens, reject the request
    if tokens < 1:
        return False
    # Enough tokens, allow the request
    else:
        client_info['tokens'] = tokens - 1
        client_info['timestamp'] = current_time
        return True

# Example usage
# defaultdict whose default value is a dictionary with keys 'tokens' and 'timestamp'
replenish_rate = 1
burst_capacity = 3
rate_limit_buckets = defaultdict(lambda: {'tokens': burst_capacity, 'timestamp': time.time()})
while 1:
    input()
    if rate_limit("user123", replenish_rate, burst_capacity):
        print("Request allowed")
    else:
        print("Request denied")

~~~
