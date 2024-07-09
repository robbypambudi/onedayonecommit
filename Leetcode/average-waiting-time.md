# Average Waiting Time

There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]: 
- arrivali is the arrival time of the ith customer.
- timei is the time needed to prepare the order of the ith customer.

When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

## Solution
1. Initialize `idleTime` to the arrival time of the first customer plus the time needed to prepare his order.
2. Initialize `waitingTime` to the difference between `idleTime` and the arrival time of the first customer.
3. Iterate over the customers array starting from the second customer.
4. If the arrival time of the customer is greater than the `idleTime`, add the time needed to prepare the order to the arrival time of the customer and update the `waitingTime`.
5. If the arrival time of the customer is less than or equal to the `idleTime`, add the time needed to prepare the order to the `idleTime` and update the `waitingTime`.
6. Return the average waiting time by dividing the `waitingTime` by the number of customers.

## Code (Naive Approach)

```cpp
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();

        double idleTime = customers[0][0] + customers[0][1];
        double waitingTime = idleTime - customers[0][0];

        for (int i = 1; i < n; i++){

            if (customers[i][0] > idleTime){
                waitingTime += (customers[i][1] + customers[i][0]) - customers[i][0];
                idleTime = customers[i][0] + customers[i][1];
            }
            else {
                idleTime += customers[i][1];
                waitingTime += (idleTime - customers[i][0]);
            }
        }

        return waitingTime / n;
    }
};
```

## Code (Optimized Approach)

```cpp
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();

        int idleTime = customers[0][0] + customers[0][1];
        double waitingTime = idleTime - customers[0][0];

        for (int i = 1; i < n; i++){

            int start_cook = max(idleTime, customers[i][0]);
            waitingTime += (start_cook + customers[i][1]) - customers[i][0];
            idleTime  = start_cook + customers[i][1];
        }

        return waitingTime / n;
    }
};
```