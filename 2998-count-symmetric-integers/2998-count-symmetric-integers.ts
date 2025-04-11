function countSymmetricIntegers(low: number, high: number): number {
    let cnt = 0;

    for (let num = low; num <= high; num++) {
        let str = num.toString();
        const len = str.length;

        if (len % 2 != 0) continue;

        let half = len / 2;
        let leftSum = 0;
        let rightSum = 0;

        for (let i = 0; i < half; i++) {
            leftSum += parseInt(str[i]);
        }
        for (let i = half; i < len; i++) {
            rightSum += parseInt(str[i]);
        }
        if (leftSum === rightSum) {
            cnt++;
        }
    }
    return cnt;
};