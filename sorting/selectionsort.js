function selectionsort(arr, lo, hi) {
	for (let i = lo; i < hi; i++) {
		let min = arr[i];
		let j = i + 1, tempind = i + 1;
		for (; j <= hi; j++) {
			if (arr[j] < min) {
				min = arr[j];
				tempind = j;
			}
		}
		let temp = arr[i];
		arr[i] = min;
		arr[tempind] = temp;
	}
}
const arr = [];
const maxsize = 6;
for (let i = 0; i < maxsize; i++) {
	arr.push(Math.floor(Math.random() * 100));
}
console.log("before sorting");
console.log(arr);
selectionsort(arr, 0, maxsize - 1);
console.log("after sorting\n");
console.log(arr);
