const { INPUT: __INPUT, INPUT_EXAMPLE } = require("./d13.test.js");

const INPUT = __INPUT;
// const INPUT = INPUT_EXAMPLE;

function getInputSize() {
  return (INPUT.length + 1) / 3;
}

/**
 *
 * @param {number} num
 * @returns [LEFT:[],RIGHT:[]]
 */
function getInput(num) {
  const cursor = num * 3;
  return [INPUT[cursor], INPUT[cursor + 1]];
}

function compareListList(leftList, rightList) {
  const minLength = Math.min(leftList.length, rightList.length);
  for (let i = 0; i < minLength; i++) {
    // if (leftList[i] >)
  }

  if (leftList.length === rightList.length) {
    return true;
  }
  if (leftList.length < rightList.length) {
    return true;
  }
  return false;
}

function compare(leftList, rightList) {
  const minLength = Math.min(leftList.length, rightList.length);
  //   console.log({ minLength });
  for (let i = 0; i < minLength; i++) {
    // console.log();
    // console.group("Loop:", i);
    try {
      let left = leftList[i];
      let right = rightList[i];
      //   console.log("Comparing I:I", left, right, typeof left, typeof right);
      if (typeof left === "number" && typeof right === "number") {
        //   console.log("Comparing I:I", left, right);
        if (left < right) {
          throw new Error(true);
        }
        if (left > right) {
          throw new Error(false);
        }
        if (left === right) {
        }
        continue;
      }
      if (typeof left === typeof right) {
        compare(left, right);
        continue;
      }

      // lift number to array
      if (typeof left === "number") {
        left = [left];
      }
      if (typeof right === "number") {
        right = [right];
      }
      compare(left, right);
      continue;
    } finally {
      //   console.groupEnd();
    }
  }

  if (leftList.length > rightList.length) {
    throw new Error(false);
  }
  if (leftList.length < rightList.length) {
    throw new Error(true);
  }
  // leftList.length == rightList.length
  // no determination
}

function begin(l, r) {
  try {
    compare(l, r);
  } catch (e) {
    return e;
  }
}

function cmpBegin(l, r) {
  const res = begin(l, r);
  if (res.message === "true") {
    return -1;
  }
  return 1;
}

function main() {
  console.log("Size:", getInputSize());

  const trueArr = [];
  const og2 = [[2]];
  const og6 = [[6]];
  const part2Arr = [og2, og6];
  for (let i = 0; i < getInputSize(); i++) {
    const [left, right] = getInput(i);
    part2Arr.push(left);
    part2Arr.push(right);
    console.group(i + 1);
    console.log({ left, right });
    const result = begin(left, right);
    console.log("Ans:", result.message);
    if (result.message === "true") {
      trueArr.push(i + 1);
    }
    console.groupEnd();
    // Process
  }
  console.log(trueArr);
  console.log(
    "Ans1:",
    trueArr.reduce((i, j) => i + j, 0)
  );

  part2Arr.sort(cmpBegin);
  let ans2og2, ans2og6;
  for (let i = 0; i < part2Arr.length; i++) {
    if (part2Arr[i] === og2) {
      ans2og2 = i + 1;
    }
    if (part2Arr[i] === og6) {
      ans2og6 = i + 1;
    }
  }
  console.log("Ans2:", ans2og2 * ans2og6);
}

main();
