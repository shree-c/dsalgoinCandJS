function merge_sort(arr, low, high) {
	if (low < high) {
		let mid = Math.floor((low + high)/2);
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}
function merge(arr, low, mid, high) {
	//two temperory arrays for holding left and right sub arrays
	let ar1 = [], ar2 = [];
	//getting those subarrays with the help of slice method
	ar1 = arr.slice(low, mid + 1);
	ar2 = arr.slice(mid + 1, high + 1);
	let v1 = 0, v2 = 0, k = low;
	//putting them back into original array by comparing elements
	const ar1l = ar1.length, ar2l = ar2.length;
	while (v1 < ar1l && v2 < ar2l) {
		if (ar1[v1] < ar2[v2]) {
			arr[k++] = ar1[v1++];
		} else {
			arr[k++] = ar2[v2++];
		}
	}
	//adding remaining elements if subarrays are of unequal size
	while (v1 < ar1l) {
		arr[k++] = ar1[v1++];
	}
	while (v2 < ar2l) {
		arr[k++] = ar2[v2++];
	}
}
const arr = [];
const maxsize = 40;
for (let i = 0; i < maxsize; i++) {
	arr.push(Math.floor(Math.random() * 100));
}
console.log("before sorting");
console.log(arr);
merge_sort(arr, 0, maxsize - 1);
console.log("after sorting\n");
console.log(arr);
