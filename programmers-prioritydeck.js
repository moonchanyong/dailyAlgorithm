// https://programmers.co.kr/learn/courses/30/lessons/42628
const curry = (f) => (a, ...bs) => bs.length === 0 ? (...bs) => f(a, ...bs) : f(a, ...bs);
const go = (val, ...fs) => reduce((val, f) => f(val), val, fs);
const printAnswer = curry((tc, str) => console.log('Case #' + (tc()) + ': ' + str));
const pipe = (...fs) => (iter) => go(iter, ...fs);
const count = curry((f, iter) => filter(f, iter).length);
/**
 * exclusive
 */
function* increment(end = Infinity) {
  var i = 0;
  while (i < end) yield i++;
}

const map = curry(function* (mapper, iter) {
  iter = iter[Symbol.iterator]();
  var result = iter.next();
  while(!result.done) {
    yield mapper(result.value);
    result = iter.next();
  }
});

const each = curry(function (pred, iter) {
  iter = iter[Symbol.iterator]();
  var result = iter.next();
  while (!result.done) {
    pred(result.value);
    result = iter.next();
  }
  return iter;
});


const reduce = curry (function(con, acc, iter) {
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

class heap{
  constructor(comp) {
    this.comp = comp; // a - b : asc 가정
    this._ = [];
    this.length = 0;
  }

  _half (num) {
    return parseInt(num / 2);
  }
  _twice (num) {
    return 2 * num;
  }
  parent (idx) {
    return this._half(idx);
  }
  _child (idx) { return  [this._twice(idx), this._twice(idx) + 1]; }
  _swap (a, b) {
    var temp = this._[a];
    this._[a] = this._[b];
    this._[b] = temp;
    return this;
  }

  heapify(idx) {
    var parenti = this.parent(idx);
    var parent = this._[parenti];
    var [childi1, childi2] = this._child(idx);
    var [child1, child2]  = [this._[childi1], this._[childi2]];
    if (child1 && child2 && this.comp(child1, child2) < 0) {
      var temp = childi1;
      childi1 = childi2;
      childi2 = temp;

      temp = child1;
      child1 = child2;
      child2 = temp;
    }
    var node = this._[idx];

    if (parent != undefined && this.comp(parent, node) < 0) {
      this._swap(idx, parenti).heapify(parenti);
    } else if (child1 != undefined && this.comp(node, child1) < 0) {
      this._swap(idx, childi1).heapify(childi1);
    } else if (child2 != undefined && this.comp(node, child2) < 0) {
      this._swap(idx, childi2).heapify(childi2);
    }
  }

  insert(val) {
    this._[this.length + 1] = val;
    this.heapify(this.length + 1);
    ++this.length;
    return this;
  }

  remove() {
    var ret = this._[1];
    this._[1] = this._[this.length];
    this._[this.length--] = undefined;
    this.heapify(1);
    return ret;
  }
}

function solution(operations) {
  var max = new heap((a, b) => (a[0] - b[0]));
  var min = new heap((a, b) => b[0] - a[0]);
  var i = 0;
  var deleted = {};
  go(
      operations,
      map(a => a.split(' ')),
      map(([a, b]) => [a, Number(b)]),
      each(([a, b]) => {
        switch(a) {
          case 'I':
            max.insert([b, i]);
            min.insert([b, i]);
            i++
            break;
          case 'D':
            if(b > 0) {
              while(max.length){
                var s = max.remove()[1];
                if (!deleted[s]) {
                  deleted[s] = 1;
                  break;
                }
              }
            }
            else {
              while(min.length){
                var s = min.remove()[1];
                if (!deleted[s]) {
                  deleted[s] = 1;
                  break;
                }
              }
            }
            break;
        }
      })
  );
  let answer = [0, 0];
  while(max.length){
    var s = max.remove();
    if (!deleted[s[1]]) {
      answer[0] = s[0];
      deleted[s[1]] = 1;
      break;
    }
  }

  while(min.length){
    var s = min.remove();
    if (!deleted[s[1]]) {
      answer[1] = s[0];
      break;
    }
  }
  return answer;
}
console.log(solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]));
console.log(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]));