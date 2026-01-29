console.log(process.memoryUsage());
var max = 2000000;
var arr = new Array();
for (let i = 0; i < max; i++) {
	arr.push(1);
}
console.log(process.memoryUsage());
