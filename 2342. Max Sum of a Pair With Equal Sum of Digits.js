/**
 * @param {number[]} nums
 * @return {number}
 */

function sumOfDigits(a){
  var sum = 0;
  while(a!=0){
    sum += a%10;
    a = Math.floor(a/10);
  }

  return sum;
}

function comparator(a,b){
  let s2 = sumOfDigits(b), s1 = sumOfDigits(a) ;

  if(s1 == s2)  return b - a;
  return s2 - s1;
}

var maximumSum = function(nums) {
  nums.sort(comparator);
  
  /*
  for(let num of nums){
    console.log(`num: ${num} and sum: ${sumOfDigits(num)}`);
  }
  */
  
  let maxi = -1;
  for(let i=0;i<nums.length-1;i++){
    let s1 = sumOfDigits(nums[i]);
    let s2 = sumOfDigits(nums[i+1]);
    
    if(s1===s2)  maxi = Math.max(nums[i] + nums[i+1], maxi);
  }

  return maxi;
};
