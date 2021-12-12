let arr = [];
const max = 100000;
for (let i = 0; i < max; i++) {
	arr.push(Math.floor(Math.random() * 100));
}

function bubblesort(arr, lo, hi) {
	for (let i = lo; i <= hi; i++) {
		for (let j = lo; j < (hi - i); j++) {
			if (arr[j] > arr[j + 1]) {
				let temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
console.log("before sorting");
console.log(arr);
bubblesort(arr, 0, max - 1);
console.log("after sorting");
console.log(arr);

