function totalFruit(fruits: number[]): number {
    let mp = new Map<number, number>();
    let maxLen = 0;
    let l = 0;

    for (let r = 0; r < fruits.length; r++) {
        mp.set(fruits[r], (mp.get(fruits[r]) || 0) + 1);

        if (mp.size > 2) {
            mp.set(fruits[l], mp.get(fruits[l])! - 1);
            if (mp.get(fruits[l]) == 0) mp.delete(fruits[l]);
            l++;
        }

        if (mp.size <= 2) {
            maxLen = Math.max(maxLen, r - l + 1);
        }
    }
    return maxLen;
};