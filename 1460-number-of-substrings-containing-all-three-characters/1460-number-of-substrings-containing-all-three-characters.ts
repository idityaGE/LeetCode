function numberOfSubstrings(s: string): number {
    const lastseen = [-1, -1, -1]
    let cnt = 0

    for(let i = 0; i < s.length; i++) {
        lastseen[s.charCodeAt(i)- 'a'.charCodeAt(0)] = i
        if(!lastseen.includes(-1)) {
            cnt += 1 + Math.min(...lastseen)
        }
    }

    return cnt
};