class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int start = 0;
        int fuel = gas[0];

        int total_gas = gas[0];
        int total_cost = cost[0];

        //whenever we have a positive fuel at a gas station, we know that this is better than starting entirely from this station
        //however, if we have a negative fuel, that means we cannot start from any of the previous station (0....i-1), we have to start from here
        for(int i=1;i<n;i++){
            fuel -= cost[i-1];
            
            if(fuel < 0){
                start = i;
                fuel = 0;
            }

            fuel += gas[i];


            total_gas += gas[i];
            total_cost += cost[i];
        }

        //if total gas is >= total cost, a trip is always possible!
        //because we will keep accumulating gas starting from the start-station, and if it was the case that during any travel we run out of fuel, then total gas wouldn't have more than total cost in the first place
        return total_gas >= total_cost ? start : -1;
    }
}
