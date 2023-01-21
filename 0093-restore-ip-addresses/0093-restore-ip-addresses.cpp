class Solution {
public:
    void dfs(vector<string>& res,string& IP,string s,int start,int part){
        if(s.size()==start && part==4){
            res.push_back(IP);
            return;
        }
        
        for(int i=start;i<s.size();i++){
            if(part < 4 && i-start < 3 && isValidIP(s,start,i)){
                IP.append(s.substr(start,i-start+1));
                part++;
                if(part<4) IP.push_back('.');               
                
                dfs(res,IP,s,i+1,part);
                
                if(part<4) IP.pop_back();
                part--;
                for(int k=0;k<i-start+1;k++) IP.pop_back();
            }
        }
    }
    
    bool isValidIP(string s,int start,int end){
        string temp = s.substr(start,end-start+1);
        int tempIP = stoll(temp);
        if(s[start] == '0' && start != end) return false;
        else if(tempIP >=0 && tempIP <= 255) return true;
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string IP;
        dfs(res,IP,s,0,0);
        return res;
    }
};