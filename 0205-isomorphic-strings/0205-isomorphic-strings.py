class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False

        d = {}
        d1 = {}


        for i in range(len(s)):
            if s[i] not in d.keys():
                d[s[i]] = t[i]
            else:
                if d[s[i]] != t[i]:
                    return False

            if t[i] not in d1.keys():
                d1[t[i]] = s[i]
            else:
                if d1[t[i]] != s[i]:
                    return False
        return True