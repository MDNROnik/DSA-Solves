class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False

        s = ''.join(sorted(s))
        t = ''.join(sorted(t))
        ans = True
        for i in range (0, len(s)):
            if s[i]!=t[i]:
                ans=False
                break

        return ans
        