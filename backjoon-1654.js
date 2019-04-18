//https://www.acmicpc.net/problem/1654
\var readline = require('readline');
var rl = readline.createInterface(process.stdin, process.stdout);


var input = [];

rl.on('line', function(line) {
  input.push(line);
}).on('close',function(){
  test(input);
  process.exit(0);
});

// class SegmentTree {
//   constructor(iter) {
//     // defensive copy
//     this.iter = [...iter];
//     this.tree = [];
//     this.lazy = [];
//     this.init(this.iter, this.tree, 1, 0, iter.length - 1);
//     return this;
//
//   }
//
//   init(iter, tree, nodeNum, start, end) {
//     if (start === end) return tree[nodeNum] = iter[start];
//     else return tree[nodeNum] = this.init(iter, tree, nodeNum * 2, start, parseInt((start + end) / 2)) +
//           this.init(iter, tree, nodeNum * 2 + 1, parseInt((start + end) / 2) + 1, end);
//   }
//
//   /**
//    * 외부 사용예 (left, right)
//    * @param nodeNum 노드 번호
//    * @param start 노드가 담당하는 시작 번호
//    * @param end 노드가 담당하는 끝 번호
//    * @param left 구하려는 인덱스의 시작
//    * @param right 구히려는 인덱스의 끝
//    */
//   sum(left, right, nodeNum = 1, start = 0, end = this.iter.length - 1) {
//     if (left > end || right < start) return 0;
//     else if (left <= start && end <= right) return this.tree[nodeNum];
//     return this.sum(left, right, nodeNum * 2, start, parseInt((start+end)/2)) +
//         this.sum(left, right, nodeNum * 2 + 1, parseInt((start+end) / 2) + 1, end);
//   }
//
//   update(left, right, val, nodeNum = 1, start = 0, end = this.iter.length - 1) {
//     if (left > end || right < start) return this.tree[nodeNum];
//     else if (start === end && left <= start && start <= right) return this.tree[nodeNum] += val; // leaf node
//     this.tree[nodeNum] += (end - start + 1) * val;
//     this.update(left, right, val, nodeNum * 2, start, parseInt((start+end)/2));
//     this.update(left, right, val, nodeNum * 2 + 1, parseInt((start+end) / 2) + 1, end);
//   }
// }

var curry = function(f) {
  return function (a, ...bs) {
   return bs.length === 0 ? function (...bs) {
      return f(a, ...bs)
    } : f(a, ...bs);
  }
}
var go = function(val, ...fs) { return reduce(function (val, f) {
  return f(val);
}, val, fs);}
var printAnswer = curry(function(tc, str) {return console.log(str)});
var pipe = function (...fs) {
  return function (iter) {
    return go(iter, ...fs);
  }
}
// var count = curry((f, iter) => filter(f, iter).length);

/**
 * implemnent this
 * @returns {Array}
 */
function preProcess(inputs) {
  return [...inputs];
}

String.prototype.hashCode = function() {
  var hash = 0, i, chr;
  if (this.length === 0) return hash;
  for (i = 0; i < this.length; i++) {
    chr   = this.charCodeAt(i);
    hash  = ((hash << 5) - hash) + chr;
    hash |= 0; // Convert to 32bit integer
  }
  return hash;
};

/**
 * logic
 * @param input
 */
function* solution(inputs) {
  var iter = inputs[Symbol.iterator]();
  let [n, k] = iter.next().value.split(' ');
  let input = [...map(Number, iter)];
  let _max = reduce(function (a, b) {
    return a>b? a:b ;
    }, input);
  // point
  var memo = {};
  var f = function (val) {
    if (memo[val]) return memo[val];
    else return reduce(function (a, b) {
      return a + parseInt(b / val);
    }, 0, input);
  };

  /**
   * 가장 처음에 나오는 값 (인덱스가 적은쪽)
   */
  const binarySearchLeft = curry(function(val, getter, low, high, isASC = true) {
    var cur = parseInt((high + low) / 2);
    if ( (val === getter(cur)) &&
        (isASC?(cur === low || val > getter(cur - 1)) : (cur === low || val < getter(cur - 1)))) return cur;
    else if(high < low) return -1;
    else return (isASC? (getter(cur) < val) : (getter(cur) > val))? binarySearchLeft(val, getter, cur + 1, high, isASC) : binarySearchLeft(val, getter, low, cur - 1, isASC);
  });

  /**
   * 가장 마지막에 나오는 값 (인덱스가 적은쪽)
   */
  const binarySearchRight = curry(function(val, getter, low, high, isASC = true) {
    var cur = parseInt((high + low) / 2);
    if (val === getter(cur) && (isASC?(cur === high || val < getter(cur + 1)) : (cur === high || val > getter(cur + 1)))) return cur;
    else if(high < low) return -1;
    else return (isASC? (getter(cur) < val) : (getter(cur) > val))? binarySearchRight(val, getter, cur + 1, high, isASC) : binarySearchRight(val, getter, low, cur - 1, isASC);
  });

  yield binarySearchRight(parseInt(k), f, 1, _max, false);
}

/**
 * seperat input
 */
function test(input) {
  var tc = 1;
  go(input,
      solution,
      each(printAnswer(''))
  );
}
// var identity = a => a;
// var remove = curry(function* (startIdx, num, iter) {
//   var i = 0, a;
//   if (arguments.length === 2) {
//     iter = num;
//     num = startIdx;
//     startIdx = 0;
//   }
//
//   for (a of iter) {
//     if (i < startIdx || i >= startIdx + num) yield a;
//     i++;
//   }
// });

/**
 * exclusive
 */
// function* increment(end = Infinity) {
//   var i = 0;
//   while (i < end) yield i++;
// }

var map = curry(function* (mapper, iter) {
  iter = iter[Symbol.iterator]();
  var result = iter.next();
  while(!result.done) {
    yield mapper(result.value);
    result = iter.next();
  }
});

var filter = curry(function* (pred, iter) {
  iter = iter[Symbol.iterator]();
  var result = iter.next();
  while(!result.done) {
    if(pred(result.value)) yield result.value;
    result = iter.next();
  }
});

var reduce = curry (function(con, acc, iter) {
  if (arguments.length === 2) {
    iter = acc;
    iter = iter[Symbol.iterator]();
    acc = iter.next().value;
  } else iter = iter[Symbol.iterator]();
  var result = iter.next();

  while (!result.done) {
    acc = con(acc, result.value);
    result = iter.next();
  }
  return acc;
});

var each = curry(function (pred, iter) {
  iter = iter[Symbol.iterator]();
  var result = iter.next();
  while (!result.done) {
    pred(result.value);
    result = iter.next();
  }
  return iter;
});

class Trie {
  varructor(iter) {
    this.finish = false;
    this.child = {}
    if (iter) each(this.insert, iter);
    return this;
  }

  insert(str) {
    if (str.length > 0) {
      this.child[str[0]] = this.child[str[0]]? this.child[str[0]] : new Trie();
      this.child[str[0]].insert(str.slice(1));
    } else {
      this.finish = true;
    }
  }

  /**
   * becareful null and false return
   * @param str
   * @param findUnique
   * @returns {null, false, Trie}
   */
  find(str, findUnique = false) {
    if (findUnique && str.length !== 0 && this.finish) return false;
    if (str.length === 0) return this;
    else if (!this.child[str[0]]) return null;
    else return this.child[str[0]].find(str.slice(1), findUnique);
  }
}

//
// // a: 배열 a
// // tree: 세그먼트 트리
// // node: 세그먼트 트리 노드 번호
// // node가 담당하는 합의 범위가 start ~ end
// long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
//   if (start === end) {
//     return tree[node] = a[start];
//   } else {
//     return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
//   }
// }