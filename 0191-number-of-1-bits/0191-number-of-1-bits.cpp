class Solution {
public:
    int hammingWeight(uint32_t n) {
        string s = bitset<32>(n).to_string(); // Convert the number to a 32-bit binary string
        
        int cnt = 0;
        
        for (char ch : s) {
            if (ch == '1') 
                cnt++;
        }
        
        return cnt;
    }
};
