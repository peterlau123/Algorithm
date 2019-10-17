class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
      
        map<int,vector<int>>dict;
        for(size_t i=0;i<times.size();i++){
            auto& s=times[i][0];
            if(dict.find(s)==dict.end()){
                vector<int>temp={i};
                dict[s]=temp;
            }else{
                dict[s].push_back(i);
            }
        }
        
         int cost=0;
         vector<bool>seen(N,0);
         queue<int>nodes;
         int visited=0;
         if(dict.find(K)==dict.end()){
             return -1;
         }else{
             nodes.push(K);
             while(!nodes.empty()){
                    int ind=nodes.front();
                     auto vec=dict[ind];
                     int max=-1;
                     int w=-1;
                     int ind_=-1;
                     for(auto e:vec)
                     {
                        ind_=times[e][1]);
                        if(seen[ind_-1])continue;
                        nodes.push(seen[ind_-1]);
                        w=times[e][2]; 
                        max=w>max?w:max;
                    }//for
                    cost+=max; 
                    nodes.pop();   
                    seen[ind-1]=1;
                    visited+=1; 
                
             }//while
         }
        
        return visited!=N?-1:cost;
    }
};

//this solution is for multiple signals can be sent from node k
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
      
        map<int,vector<int>>dict;//id---indexes
        map<int,int>seen;//id----reaceived time
        for(size_t i=0;i<times.size();i++){
            auto& s=times[i][0];
            if(dict.find(s)==dict.end()){
                vector<int>temp={i};
                dict[s]=temp;
                
                seen[s]=-1;//time clock
            }else{
                dict[s].push_back(i);
            }
            
            s=times[i][1];
            if(dict.find(s)==dict.end()){
                dict[s]={};
                
                seen[s]=-1;//time clock
            }
        }
        
         queue<int>nodes;
       
         if(dict[K].size()==0){
             return -1;
         }else{
             nodes.push(K);
             seen[K]=0;
             int cost,cost_;
             int ind,ind_;
             while(!nodes.empty()){
                    ind=nodes.front();
                    cost=seen[ind];
                 
                    auto vec=dict[ind];
                    for(auto e:vec)
                    {
                        ind_=times[e][1];
                        cost_=cost+times[e][2];//the time to reach the target node
                        if(seen[ind_]==-1||seen[ind_]>cost_){
                            seen[ind_]=cost_;
                            nodes.push(ind_);
                        }
                    }//for
                    nodes.pop();   
             }//while
         }
        
        int result=-1;
        for(auto itr=seen.begin();itr!=seen.end();itr++){
            if(itr->second==-1)return -1;
            result=itr->second>result?itr->second:result;
        }
        
        return result;
    }
};