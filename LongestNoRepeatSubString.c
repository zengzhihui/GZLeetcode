int contains(char *s, int start, int end, char tmps) {
    if (s == NULL) {
        return -1;
    }
    
    int result = -1;
    for (int index = start; index <= end; index ++) {
        if(s[index] == tmps) {
            result = index;
            break;
        }
    }
    return result;
}

int lengthOfLongestSubstring(char* s) {
    if (s == NULL) {
        return 0;
    }
    int ans = 0;
    int longestStart = 0;
    int longestEnd = 0;
    
    int length = strlen(s);
    char* sub = (char*)malloc(sizeof(char) * length);
    int i = 0;
    int j = 0;
    
    int subStart = 0;
    int subEnd = 0;

    while (j < length) {
        int result = contains(sub, subStart, subEnd, s[j]);
        if(result == -1) {
            sub[subEnd] = s[j];
            subEnd = subEnd + 1;
            j = j + 1;
            int maxLength = subEnd - subStart;
            if (ans < maxLength) {
                ans = maxLength;
                longestStart = subStart;
                longestEnd = subEnd;
            }
        } else {
            subStart = result + 1;
        }
    } 
    
    if (sub != NULL) {
        free(sub);
        sub = NULL;
    }
    // for (int index = longestStart; index < longestEnd; index ++ ) {
    //     printf("%c", s[index]);
    // }
    return ans;
}
