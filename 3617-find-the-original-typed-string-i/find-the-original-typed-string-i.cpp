class Solution {
public:
    int possibleStringCount(string w) {
        int c=0;
        for(int i=1;i<w.size();){
            while(w[i]==w[i-1]){
                c++;
                i++;
            }
            i++;
        }
        return c+1;
    }
};