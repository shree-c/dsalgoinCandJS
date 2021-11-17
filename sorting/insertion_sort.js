let arr = [22, 34, -1, 22, -24, 0, 5];
for (let i = 0; i < arr.length; i++) {
  for (let j = i; j > 0 && arr[j-1] > arr[j]; j--) {
    if (arr[j - 1] > arr[j]) {
      let temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
    }
    console.log(arr);
  }
  console.log(`loop count: ${i}`);
}


