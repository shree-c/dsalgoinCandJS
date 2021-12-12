function quicksort(A, lo, hi) {
	if (lo >= hi || lo < 0)
		return;
	let p = partition(A, lo, hi);
	quicksort(A, lo, p - 1);
	quicksort(A, p + 1, hi);
}

function swap(A, B) {
	let temp = A;
	A = B;
	B = temp;
}
function partition(A, lo, hi) {
	//setting pivot as last element
	let pivot = A[hi];
	let i = lo - 1;

	for (let j = lo; j < hi; j++) {
		if (A[j] <= pivot) {
			i++;
			let temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	i++;
	let temp = A[i];
	A[i] = A[hi];
	A[hi] = temp;
	return i;
}

const MAX = 20;
let A = [];
for (let i = 0; i < MAX; i++) {
	A.push(Math.floor((Math.random() * 50)));
}
console.log("before sorting");
console.log(A);
quicksort(A, 0, MAX - 1);
console.log("after sorting");
console.log(A);
