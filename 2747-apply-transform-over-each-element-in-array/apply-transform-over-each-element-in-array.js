/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let lenght = arr.length;
    for(let i=0;i<lenght;i++){
        arr[i] = fn(arr[i], i); 
    }
    return arr;
};