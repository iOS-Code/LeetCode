// 定义一个数组来记录数据 是否有重复的字符
int lengthOfLongestSubstring(char* s) {
    int maxlen = 0,currlen = 0;
    int table[128], i, j, start = 0;
    memset(table, 0, sizeof(table));
    for (i = 0; s[i] != '\0'; ++i){ // 只要字符串每结束就循环
        if( (++table[s[i]]) == 2 ){ // 只要是第一次出现的字符，就将table[s[i]]置为1，已出现则重复，table[s[i]]==2
            if (currlen > maxlen){
                maxlen = currlen;
            }
            for(j = start; j < i; ++j){
                if (s[j] == s[i]){ // 出现重复位置了，比如abcdcd  s[2] == s[4]
                    table[s[j]] = 1;
                    start = j+1; // start记录出现重复的字符的后一个位置，比如还有字符串abcdcd,start = 3
                    break;
                }else{
                    --currlen;
                    table[s[j]] = 0;// 还拿字符串abcdcd举例，将tables['a'] = 0,tabels['b']=0;方便下一次查找
                }
            }
        }else{ // 没有重复的字出现，累计子串长度
            ++currlen;
        }
    }
    if (currlen > maxlen){ //全部字符不重复
        maxlen = currlen;
    }
    return maxlen;
}


// 从前向后循环 计算每个字符开始的最长不重复字符
int lengthOfLongestSubstring(char* s)
{
    int i, j, k, isRepeat;
    int temp, maxlen = -1;
    int len = strlen(s);
    if (len == 0) return 0;
    for(i = 0; i < len; i++) //循环每个字符
    {
        j = i + 1;
        temp = 1;
        isRepeat = 0;//出现重复字符就置1
        while(j < len && isRepeat == 0)//从i的下一个字符开始统计s[i]字符的最长不重复字串
        {
            k = i;
            while(k < j)//j和i~j-1的每个字符做比较，不等才能字串长+1
            {
                if(s[j] != s[k])    k++;
                else{
                    isRepeat = 1;
                    break;
                }
            }
            if(k == j){//当前j所对应字符第一次出现
                j++;
                temp++;
            }
        }
        maxlen = maxlen > temp?maxlen:temp;
    }
    return maxlen;
    
}
