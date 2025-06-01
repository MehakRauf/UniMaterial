// function startTest() {
//     if (testActive) return;
//     testActive = true;
//     startTime = Date.now();
//     clickCount = 0;
//     while (Date.now() - startTime < 10000) {
//     alert(`Alert ${clickCount + 1}`);
//     clickCount++;
//     }
//     const average = (clickCount / 10).toFixed(2);
//     startTimeDisplay.textContent = new

//     Date(startTime).toLocaleTimeString();

//     averageDisplay.textContent = average;
//     const resultsStart = Date.now();
//     while (Date.now() - resultsStart < 2000) {
//     alert(`Average speed: ${average} alerts/sec`);
//     }
//     testActive = false;
// }
// startTest()

// const wizard = {
//     magicNumber: 50,
//     castSpell: function (){
//         console.log(this.magicNumber);
//     }
// }

// wizard.castSpell();

// const hero = {
//     name: "Thor",
//     greet: function () {
//         const inner = function () { // by changing this to an arrow function then it won't be undefined
//             console.log(`Hello, I am ${this.name}`);
//         }
//         inner();
//     }
// }

// hero.greet();

// const wizard = {
//     magicNumber: 42,

//     spell: function (a, b) {
//         console.log(`Magic Boost: ${this.magicNumber}`);
//         return a + b + this.magicNumber;
//     }
// };

// console.log(wizard.spell(10, 5));

// let sum = 0;
// for (let i = 0; i < 10; i++) {
//     sum += i;
// }
// console.log(sum);

// sum = 0;
// let k = 0;
// while (k <= 10) {
//     sum += k;
//     k++;
// }
// console.log(sum);

// sum = 0;
// k = 0;
// do {
//     sum += k;
//     k++;
// } while (k <= 11);
// console.log(sum);

// let obj = {
//     "mehak": 0,
//     "harry": 1
// };

// for (let key in obj) {
//     console.log(key);
// }

// let o1 = [1, 2, 3, 4];
// for (let value of o1) {
//     console.log(value);
// }

// let str = "Mehak Fatima";
// let str1 = "Kainat";

// console.log(str.concat(str1));
// console.log(str.length);
// console.log(str.toLowerCase());
// console.log(str.toUpperCase());
// console.log(str.slice(2));
// console.log(str[0]);
// console.log(str[str.length - 1]);
// console.log(str.slice(0, -1));
// console.log(str.replace("Meh", "meh"));
// console.log(str.includes("atima"));
// console.log(str.startsWith("Meh"));

// let arr = [8, 9, 4, 0, 22, 14, 2, 3, 4, 5];

// console.log(arr.length);
// console.log(arr.pop()); // returns the popped element from the last// updates the array
// console.log(arr.push(3)); // returns the length of the array // updates the array
// console.log(arr); // to print the array
// console.log(arr.shift());// returns the removed element from the start
// console.log(arr.unshift(2)); // returns the length of the array after adding an element at the start of the array
// console.log(arr.join("_"));// returns an string
// console.log(arr.concat("Hello"));// returns a new array
// console.log(arr);
// console.log(arr.sort()); // by defualt it sorts alphabetically
// let compare = (a, b) => {
//     return b-a; // for descending 
//     // for ascending use a-b
// }
// console.log(arr.sort(compare))

// arr.map(el => console.log(el));
// arr.forEach((el) => {
//     console.log(el);
// })
// let a1 = arr.filter(el => {
//     return (el < 10);
// })
// console.log(a1);

// let a2 = arr.reduce((a, b) => {
//     return (a + b);
// })
// console.log(a2);

