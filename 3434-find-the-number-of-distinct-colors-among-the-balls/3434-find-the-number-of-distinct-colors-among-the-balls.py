from collections import defaultdict

class Solution:
    def queryResults(self, limit: int, queries: list[list[int]]) -> list[int]:
        key_to_value = {}  # Stores key -> value
        value_count = defaultdict(int)  # Tracks occurrences of values
        result = []
        distinct_values = 0

        for key, value in queries:
            # If key already exists, decrease count of old value
            if key in key_to_value:
                old_value = key_to_value[key]
                value_count[old_value] -= 1
                if value_count[old_value] == 0:
                    distinct_values -= 1  # Remove old value if count reaches 0

            # Assign new value to key
            key_to_value[key] = value
            if value_count[value] == 0:
                distinct_values += 1  # New distinct value added
            value_count[value] += 1

            result.append(distinct_values)

        return result
