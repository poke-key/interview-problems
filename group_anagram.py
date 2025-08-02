class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:


        anagram_groups = {}

        for s in strs:
            sorted_key = ''.join(sorted(s)) #sort all the word's letters

            if sorted_key in anagram_groups:
                anagram_groups[sorted_key].append(s) #add to the dictionary of anagrams
            else:
                anagram_groups[sorted_key] = [s]

        return list(anagram_groups.values())
        