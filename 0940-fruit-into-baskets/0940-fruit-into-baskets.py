class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        fruit_count = {}
        max_len = 0
        left = 0

        for right in range(len(fruits)):
            fruit_count[fruits[right]] = fruit_count.get(fruits[right], 0) + 1

            if len(fruit_count) > 2:
                fruit_count[fruits[left]] -= 1
                if fruit_count[fruits[left]] == 0:
                    del fruit_count[fruits[left]]
                left += 1

            if len(fruit_count) <= 2:
                max_len = max(max_len, right - left + 1)

        return max_len
        