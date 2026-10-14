/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let curr_count = n-1;
    
    return function() {
     curr_count+=1;
     return curr_count;
        
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */