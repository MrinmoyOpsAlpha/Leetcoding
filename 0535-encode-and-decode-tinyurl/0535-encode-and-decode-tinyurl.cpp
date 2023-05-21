class Solution {
private:
    unordered_map<string,string> long_to_short;
    unordered_map<string,string> short_to_long;
    
    int hash = 0;
    uint64_t hash_function(const string& str){
        hash = 100 * hash;
        hash++;
        return hash;
    } 
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        long_to_short[longUrl] = "http://tinyurl.com/" + to_string(hash_function(longUrl));
        short_to_long[long_to_short[longUrl]] = longUrl;
        return long_to_short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));