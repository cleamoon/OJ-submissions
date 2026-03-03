/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function binary_search(nums, target, begin, end) {
    if (begin === end) {
        if (nums[begin] === target) return begin
        else return -1
    }
    const mid = Math.floor((begin + end) / 2)
    const pivot = nums[mid]
    if (pivot === target) return mid
    else if(pivot < target) return binary_search(nums, target, mid + 1, end)
    else return binary_search(nums, target, begin, mid)
}

function find_rot(nums, begin, end) {
    if (begin + 1 === end) return begin
    const mid = Math.floor((begin + end) / 2)
    const pivot = nums[mid]
    if (pivot > nums[end - 1]) {
        if (nums[mid] > nums[mid + 1]) return mid
        return find_rot(nums, mid, end)
    } else {
        if (nums[mid - 1] > nums[mid]) return mid - 1
        return find_rot(nums, begin, mid)
    }
}

var search = function(nums, target) {
    if (nums[0] < nums[nums.length - 1]) 
        return binary_search(nums, target, 0, nums.length)
    const rot = find_rot(nums, 0, nums.length)
    console.log('rot: ', rot)
    const f1 = binary_search(nums, target, 0, rot + 1)
    if (f1 >= 0) return f1
    return binary_search(nums, target, rot + 1, nums.length)
};