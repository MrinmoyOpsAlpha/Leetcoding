class LFUCache {
public:
    LFUCache(int _capacity) {
        capacity=_capacity;
        size=0;
        min_freq=0;
    }
    
    int get(int key) {
        if(keysInfo.count(key)==0){
            return -1;
        }
        update(key);
        return keysInfo[key].first;
    }
    
    void put(int key, int value) {
        if(capacity<=0)
            return;
        
        if(keysInfo.count(key)==1){      //If key is already present 
            //update value
            keysInfo[key].first=value;
            update(key);
        }
        else{
            if(size==capacity){
                int key_to_remove=freq_to_key[min_freq].front();
                /*
                Remove from all three maps
                */
                freq_to_key[min_freq].pop_front();
                keysInfo.erase(key_to_remove);
                um_ref.erase(key_to_remove);
            }
            else
                size++;
            
            keysInfo[key]={value,1};
            min_freq=1;
            freq_to_key[1].push_back(key);
            um_ref[key]=(--freq_to_key[1].end());
        }   
    }
    
private :
    int capacity;
    int size;
    int min_freq;
    
    unordered_map<int,list<int> > freq_to_key;
    unordered_map<int,pair<int,int> > keysInfo;    //(key to {value,freq});
    unordered_map<int, list<int>::iterator> um_ref; //key to its iterator in freq_to_key list
    
    
    void update(int key){
        int curr_freq=keysInfo[key].second;
        auto it=um_ref[key];
        keysInfo[key].second++;
        freq_to_key[curr_freq].erase(it);
        curr_freq++;
        freq_to_key[curr_freq].push_back(key);
        um_ref[key]=(--freq_to_key[curr_freq].end());
        
        if(freq_to_key[min_freq].empty())
            min_freq++;
    }
};
