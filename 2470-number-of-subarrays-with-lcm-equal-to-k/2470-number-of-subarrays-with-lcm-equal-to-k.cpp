class Solution {
private:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;

        for (int j = 0; j < nums.size(); j++) {
            int curr = nums[j];
            if (curr == k) cnt++;

            for (int i = j + 1; i < nums.size(); i++) {
                curr = lcm(curr, nums[i]);

                if (curr == k) cnt++;
                else if (curr > k) break; // break if LCM exceeds k
            }
        }

        return cnt;
    }
};
