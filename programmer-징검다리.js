// https://programmers.co.kr/learn/courses/30/lessons/43236
function decision(rocks, n, x) {
  var cnt = 0;
  var gap = -1;
  for (let i = 0; i < rocks.length; i++) {
    if(gap <= rocks[i]) {
      cnt++;
      gap = rocks[i] + x;
    }
  }
  return cnt >= n;
}

function solution(distance, rocks, n) {
  var answer = 0;
  var lo = 0, hi = distance + 1;
  rocks.push(0);
  rocks.push(distance);
  rocks = rocks.sort((a, b) => a - b);
  console.log(rocks);
  n = rocks.length - n ;
  for (let i = 0; i < 10000; i++) {
    var mid = (lo + hi) / 2;
    if (decision(rocks, n, mid)) lo = mid;// x 증가
    else hi = mid;  // x 감소
  }

  return parseInt(lo);
}

console.log(solution(25, [2, 14, 11, 21, 17], 2));