class Solution {
    
//by liuxin on 17.4.20    
public:

    void swap(char&a,char&b)
    {
       char tmp=a;
        a=b;
        b=tmp;    
    }
    string reverseVowels(string s) 
    {
        int len=s.size();
        string result;
        if(len==0)return result;
        if(len==1)return s;
        
        int i=0;
        int j=len-1;
        
        //指定元音查找集合
        unordered_set<char> arr={'a','A','e','E','i','I','o','O','u','U'};
        
        //两个序号相向遍历
        while(i<=j)
        {
            unordered_set<char>::iterator itri=arr.find(s[i]);//average find time :constant,worst case linear
            unordered_set<char>::iterator itrj=arr.find(s[j]);
            
            if(i<=j&&itri==arr.end())
            {
                i++;
            }else{
                
                if(i>j){break;}
                
                if(itrj==arr.end())
                {
                    j--;    
                }else{
                    //i,j所在的元素均为元音，则交换
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                
            }
  
        }
        
     return s;   
       
    }
    
    
};