type F = (x: number) => number;

function compose(fn: F[]): F {
    if (fn.length == 0) {
        return function (x) { return x; }
    }

    return fn.reduceRight((prevFn, nextFn) => {
        return (x) => {
            return nextFn(prevFn(x));
        }
    })
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */