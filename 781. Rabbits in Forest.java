/*
We asked n rabbits "How many OTHER rabbits have the same color as you?" 

Pair up the rabbits belonging to same group (same answer)
The pair would contain ans+1 rabbits (remember, ans means there are other ans rabits of the same color)
The remaining ones that can not be paired up, take extra count (= didn't answer) to pair them up

*/

class Solution {
    public int numRabbits(int[] arr) {
        int ans = 0;
        Map<Integer,Integer> m = new HashMap<>();

        for(int u: arr){
            m.put(u, m.getOrDefault(u,0) + 1);
        }

        for(int key: m.keySet()){
            //Pair up the rabbits belonging to same group (same key)
//The pair would contain key+1 rabbits (remember, a answer = key means there are other 'key' rabits of the same color)
            int val = m.get(key);
            int need = key+1;
            ans += val/need * need;

            //The remaining ones that can not be paired up, take extra count (= didn't answer) to pair them up                
            if(val%need != 0)  ans += need;
        }

        return ans;
    }

    //1:2, 2:1
    // key = 1, need = 2, val = 2
    // ans += 2
    // key = 2, need = 3, val = 1
    // ans += 3
}
