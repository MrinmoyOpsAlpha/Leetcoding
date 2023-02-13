class Solution {
public:

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
        auto comp = [](pair<int, int> &a, pair<int, int> &b){
          if(a.first == b.first) return a.second > b.second;
          return a.first < b.first;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        unordered_set<string> pos, neg;
        for(auto s: positive_feedback) pos.insert(s);
        for(auto s: negative_feedback) neg.insert(s);

        int n = report.size();

        for(int i=0;i<n;i++){
            int cnt = 0;
            stringstream ss(report[i]);
            string word;

            while(ss >> word){
                if(pos.find(word) != pos.end()) cnt += 3;
                else if(neg.find(word) != neg.end()) cnt -= 1;
            }
            pq.push({cnt,student_id[i]});
        }

        vector<int> ans;

        while(pq.size() > 0 && k--){
            int top = pq.top().second;
            ans.push_back(top);
            pq.pop();
        }
        return ans;
    }
};
