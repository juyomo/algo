// Author: Juyoung Moon
// https://leetcode.com/problems/roman-to-integer/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 17, 2025)

// HW are the following 5 problems:
// 1. Diameter of Binary Tree
// 2. Middle of the Linked List
// 3. Maximum Depth of Binary Tree
// 4. Contains Duplicate
// 5. Roman to Integer

/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
    const m = new Map();
    m.set('I', 1);
    m.set('V', 5);
    m.set('X', 10);
    m.set('L', 50);
    m.set('C', 100);
    m.set('D', 500);
    m.set('M', 1000);

    let sum = 0;
    for (let i = 0; i < s.length; i++) {
        let curr = s[i];
        let next = i < s.length - 1 ? s[i+1] : '_';
        let sign = 1;
        if (m.get(curr) < m.get(next)) {
            sign = -1;
        }

        sum += sign * m.get(curr);
    }
    return sum;
};
