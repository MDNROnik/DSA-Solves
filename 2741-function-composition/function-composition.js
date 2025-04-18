/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        let len = functions.length;
        len-=1;
        for(let i=len;i>=0;i--){
            x = functions[i](x);
            // console.log(x);
        }
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */