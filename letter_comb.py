class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        #use hash map

        if not digits:
            return []
        
        res = []

        digit_to_letter_map = {
            '2': 'abc',
            '3': 'def', 
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        def backtrack(index: int, curr_comb: str):

            if index == len(digits):
                res.append(curr_comb)
                return
            current_digit = digits[index]
            letters = digit_to_letter_map[current_digit]

            for letter in letters:
                backtrack(index + 1, curr_comb + letter)
            
        backtrack(0, "") #start with empty string

        return res

