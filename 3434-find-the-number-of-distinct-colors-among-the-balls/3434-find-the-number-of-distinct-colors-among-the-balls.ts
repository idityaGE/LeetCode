function queryResults(limit: number, queries: number[][]): number[] {
    const keyToValue = new Map<number, number>();  // Stores key -> value
    const valueCount = new Map<number, number>();  // Tracks occurrences of values
    const result: number[] = [];
    let distinctValues = 0;

    for (const [key, value] of queries) {
        // If key already exists, decrease count of old value
        if (keyToValue.has(key)) {
            const oldValue = keyToValue.get(key)!;
            valueCount.set(oldValue, (valueCount.get(oldValue) ?? 0) - 1);
            if (valueCount.get(oldValue) === 0) {
                distinctValues--; // Remove old value if count reaches 0
            }
        }

        // Assign new value to key
        keyToValue.set(key, value);
        if (!valueCount.has(value) || valueCount.get(value) === 0) {
            distinctValues++; // New distinct value added
        }
        valueCount.set(value, (valueCount.get(value) ?? 0) + 1);

        result.push(distinctValues);
    }

    return result;
}
