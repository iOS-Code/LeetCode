/**
2147483647 = 2^31-1   32位操作系统中最大的符号型整型常量  INTMAX
 
 JAVA C C++ Python等实现
 */


public class Solution {
    public int reverse(int x) {
        int flag=x>0?1:-1,res=0;
        x=x>0?x:-x;
        while(x>0){
            if(res*10.0 + x%10 > 2147483647)return 0;
            res = res*10+x%10;
            x/=10;
        }
        return res*flag;
    }
} 




int reverse(int x) {
    int flag=x>0?1:-1,res=0;
    x=x>0?x:-x;
    while(x>0){
        if((2147483647.0-x%10)/10<res)return 0;
        res=res*10+x%10;
        x=x/10;
    }
    return res*flag;
}




class Solution {
public:
    int reverse(int x) {
        int flag=x>0?1:-1,res=0;
        x=x>0?x:-x;
        while(x>0){
            if(res*10.0+x%10 > 2147483647)return 0;
            res = res*10+x%10;
            x/=10;
        }
        return res*flag;
    }
};



class Solution:
# @param {integer} x
# @return {integer}
def reverse(self, x):
flag=1 if x>0 else -1
x=x if x>0 else -x
res=0
while x>0:
if res*10.0 + x%10 > 2147483647:return 0
res = res*10+x%10
x/=10
return res*flag
