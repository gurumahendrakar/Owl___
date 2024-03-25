const assert = require('node:assert');
const { getRandomValues } = require('node:crypto');

// Generate an AssertionError to compare the error message later:
// const {message}  = new assert.AssertionError({
//   actual: 1,
//   expected: 2,
//   operator: 'strictEqual',
//   message : "Given Arguments Are Not Equal"
// });

// try {
//   assert.strictEqual(1, 2);
// } catch (err) {
//     assert.deepEqual(err.message,message)
// }

const tracker = new assert.CallTracker();


function func(a,b,c){
    return ("Function Called",a,b,c)
    
}

const callsfunc = tracker.calls(func,2)
callsfunc(1,2,3)
callsfunc(1,2,3)
tracker.reset(callsfunc)
console.log(tracker.getCalls(callsfunc))
