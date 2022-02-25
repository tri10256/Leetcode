class Solution {
public:
    int compare(string &version1,string &version2){
        
        int i = 0;
        int j = 0;
        int n = version1.size();
        int m = version2.size();
        
        int digit1 = 0;
        int digit2 = 0;
        while(i<n && j<m){
            if(version1[i]=='.' && version2[j] == '.'){
                if(digit1<digit2){
                    return -1;
                }
                if(digit1 > digit2){
                    return 1;
                }
                digit1 = 0;
                digit2 = 0;
                i++;
                j++;
            }else if(version1[i] == '.' && version2[j] != '.'){
                digit2 = digit2*10+(version2[j] - '0');
                j++;
            }else if(version1[i] != '.' && version2[j] == '.'){
                digit1 = digit1*10 + (version1[i] - '0');
                i++;
            }
            else{
              digit1 = digit1*10 + (version1[i] - '0');
                i++;
              digit2 = digit2*10 + (version2[j] - '0');
                j++;
            }
        }
        
        while(i<n){
             if(version1[i] =='.'){
                if(digit1>digit2)
                    return 1;
                else if(digit2>digit1){
                    return -1;
                }
              digit1 = 0;
              digit2 = 0;
              i++;
           }
          else{
              digit1 = digit1*10 + (version1[i] - '0');
                i++;
          }
        }
        while(j<m){
            if(version2[j] =='.'){
                if(digit1>digit2)
                    return 1;
                else if(digit2>digit1){
                    return -1;
                }
              digit2 = 0;
              digit1 = 0;
              j++;
           }else{
                digit2 = digit2*10 + (version2[j] - '0');
                j++;
            }
        }
      
               if(digit1<digit2){
                    return -1;
                }
                if(digit1 > digit2){
                    return 1;
                }
    
        
        return 0;
    }

    int compareVersion(string version1, string version2) {
        return compare(version1,version2);
    }
};