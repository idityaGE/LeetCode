type F = (x: number) => number;

function compose(fn: F[]): F {

    return (x) => {
        let result = x;
        for (let i = fn.length - 1; i >= 0; i--) {
            result = fn[i](result);
        }
        return result;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */