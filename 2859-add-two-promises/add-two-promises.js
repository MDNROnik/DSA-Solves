/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    let res = 0;
    try{
        let value = await promise1;
        res+=value
        console.log(value);
    }catch(error){

    }

    try{
        let value = await promise2;
        res+=value
        console.log(value);
    }catch(error){

    }

    return res;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */