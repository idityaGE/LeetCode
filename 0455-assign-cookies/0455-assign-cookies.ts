function findContentChildren(g: number[], s: number[]): number {
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);

    let p = 0, i = 0;

    while (p < g.length && i < s.length) {
        if (g[p] <= s[i]) {
            p++;
        }
        i++;
    }

    return p;
};