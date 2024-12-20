function reverseBits(n: number): number {
    let res = 0;
    for (let i = 0; i < 32; i++) {
        res = (res << 1) | (n & 1);
        n >>>= 1;
    }
    return res >>> 0;
};
