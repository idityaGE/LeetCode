type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
    
    return async function(...args) {
        const originalFnPromise = fn(...args);
        const timoutPromise = new Promise((_, rej) => {
            setTimeout(() => {
                rej("Time Limit Exceeded")
            }, t)
        })

        return Promise.race([originalFnPromise, timoutPromise])
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */