class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        list = []
        dict = {}
        for index in range(0, len(strs)):
            sorted_string = ''.join(sorted(strs[index]))
            if sorted_string not in dict:
                dict[sorted_string] = []
            dict[sorted_string].append(strs[index])
        
        for key, value in dict.items():
            list.append(value)

        return list
        