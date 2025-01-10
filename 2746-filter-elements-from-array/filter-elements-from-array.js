/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let siz = arr.length;
    console.log(siz);
    let newArray = [];
    for(let i=0;i<siz;i++){
        let value = fn(arr[i],i);
        console.log(value);
        if ( value == true || value != 0 ) {
            //console.log(11111);
            //console.log(arr[i], i);
            newArray.push(arr[i]);
        }
        else{
            //console.log(2222);
            //console.log(arr[i], i);
        }
    }
    return newArray;
};