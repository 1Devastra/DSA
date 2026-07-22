class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        # for i in range (len(s)):
        #     count=0
        #     for j in range(len(s)):
        #         if s[i]==s[j]:
        #             count=count+1
        #     if count ==1:
        #         return i
        # return -1
        freq={}
        for k in s:
            if k in freq:
                freq[k]= freq[k]+1
            else:
                freq[k]=1
        for i in range (len(s)):
            if freq[s[i]]==1:
                return i
        return -1