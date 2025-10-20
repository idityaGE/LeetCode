class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        X = 0
        for oper in operations:
            for ch in oper:
                if ch != 'X':
                    if ch == '+':
                        X += 1
                    else:
                        X -= 1
                    break

        return X  

        