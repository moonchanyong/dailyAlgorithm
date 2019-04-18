
// https://programmers.co.kr/learn/courses/30/lessons/42886
function solution(weight) {
  weight.sort((a, b) => a - b);
  var len = weight.length,
  i = 0;
  if (weight[i] !== 1) return 1;
  var sum = 1;
  while (++i < len) {
    if (sum >=  weight[i] - 1) {
      sum += weight[i];
    }
    else break;
  }

  if (sum + 1 === weight[i]) return weight[i] + 1;
  return sum + 1;
}

console.log(solution([ 1, 1, 2, 3, 6, 7, 21 ]));