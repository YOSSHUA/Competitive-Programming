#  https://leetcode.com/problems/group-anagrams/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for i in range(len(strs)):
            let = {}
            for c in strs[i]:
                let[c] = let.get(c,0) + 1

            cad = ''
            for l, c in sorted(let.items()):
                cad += l + str(c)

            groups[cad] = groups.get(cad, []) + [i]

        return [[strs[e] for e in groups[pat]] for pat in groups.keys()]