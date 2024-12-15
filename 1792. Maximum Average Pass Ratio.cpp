/*
Time: O(nlogn)
Space: O(n)

Use Priority Queue based on the priority of Gain (the increase in pass rate for one extraordinary student insertion)

Then iterate over each extraordinary student, and on each iteration, find the class that will give highest gain if a passing student is inserted

*/


class Solution {
public:
    typedef pair<double,double> pdd;

    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        int n = classes.size();

        auto cmp = [](pdd &a, pdd &b){
            double a_avg = a.first/a.second;
            double b_avg = b.first/b.second;

            return (a.first + 1.0)/(a.second + 1.0) - a_avg < (b.first + 1.0)/(b.second + 1.0) - b_avg; // 'gain' by adding one extra-ordinary student to passed (and total) student's list
        };

        priority_queue<pdd, vector<pdd>, decltype(cmp)> pq(cmp);

        for(auto &u: classes)  pq.push({u[0], u[1]});

        //Then iterate over each extraordinary student, and on each iteration, find the class that will give highest gain if a passing student is inserted
        for(int i=0;i<extra;i++){
            const pdd p = pq.top();
            pdd added = {p.first+1, p.second+1};
            pq.pop();

            pq.push(added);
        }

        double sum = 0;
        while(!pq.empty()){
            pdd p = pq.top();
            pq.pop();

            //cout<<p.first<<" "<<p.second<<endl;
            
            sum += p.first/p.second;
        }

        double avg = sum / n;
        return avg;
    }
};
