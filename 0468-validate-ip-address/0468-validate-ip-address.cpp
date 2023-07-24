class Solution {
    vector<string> split(string s,char ch){
        vector<string> parts;
        string part;
        istringstream in(s);
        while(getline(in,part,ch)){
            parts.push_back(part);
        }
        
        return parts;
    }
    
    bool checkIPv4(string IP){
        if (count(IP.begin(), IP.end(), '.') != 3) {
            return false;
        }
        
        vector<string> parts = split(IP,'.');
        if(parts.size()!=4) return false;
        
        for(string part:parts){
            if (part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0') {
                return false;
            }
            
            for(char c:part){
                if(!isdigit(c)) return false;
            }
            
            if(stoi(part) > 255) return false;
        }
        return true;        
    }
    
    bool checkIPv6(string IP){
        if (count(IP.begin(), IP.end(), ':') != 7) {
            return false;
        }
        
        vector<string> parts = split(IP,':');
        if(parts.size() != 8) return false;
        
        for(string part:parts){
            if (part.empty() || part.size() > 4) {
                return false;
            }
            
            for(char c: part){
                if(!isdigit(c) &&  (!isalpha(c) || toupper(c) > 'F')) return false;
            }
        }
        
        return true;
    }
    
public:
    string validIPAddress(string queryIP) {
        return checkIPv4(queryIP) ? "IPv4" : (checkIPv6(queryIP) ? "IPv6" : "Neither");
    }
};