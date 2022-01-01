let gaps = [ 701, 301, 132, 57, 23, 10, 4, 1 ];
let arr = [];
const max = 10;
for (let i = 0; i < max; i++) {
	arr.push(Math.floor(Math.random() * 100));
}
console.log('before');
console.log(arr);
for (let gap of gaps) {
	for (let offset = 0; offset < gap; offset++) {
		for (let j = offset; j < max; j += gap) {
			let k = j + gap;
			let temp = arr[k];
			for (; k >= gap && arr[k - gap] > temp; k -= gap) {
				arr[k] = arr[k - gap];
			}
			arr[k] = temp;
		}
	}
}

function sorted(arr, max) {
	for (let i = 1; i < max; i++ ) {
		if (arr[i] < arr[i - 1])
			return false
	}
	return true;
}
console.log(arr);
console.log(sorted(arr, max));
