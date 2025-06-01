// console.log('start');

// setTimeout(() => {
// console.log(`understand asynchronous javascript 2`);}, 5000);

// setTimeout(() => {
// console.log(`understand asynchronous javascript 1`);}, 0);

// console.log('end');

// console.log('start');

// setTimeout(() => {

// console.log('setTimeout function executed');}, 0);

// new Promise((resolve, reject) => { resolve('Promise resolved'); } )

// .then((res) => console.log(res))

// .catch((err) => console.log(err));

// console.log('end');

// for (var i=1; i<=10; i++){
//     setTimeout(function(){
//         console.log(i);
//     },1000);
// }

// function fn(i) {
//     setTimeout(function () { console.log(i); }, 1000 * i);
//     }
//     for (var i = 1; i <= 10; i++) fn(i);

// for (let i=1; i<=10; i++){
//     setTimeout(function(){
//         console.log(i);
//     },1000*i);
// }

// class Game {
//     constructor(n) {
//         this.name = n;
//     }
//     printName() {
//         console.log(this.name);
//     }
// }

// let g1 = new Game("Chess");
// let g2 = new Game("Football");

// console.log(g1.printName === g2.printName);

// class Game {
//     Game(n) {
//         console.log("game method is called")
//         this.name = n;
//     }
//     printName() {
//         console.log(this.name);
//     }
// }

// let g1 = new Game("Chess");
// // let g2 = new Game("Football");

// g1.printName();

// console.log(g1.printName === g2.printName);

// class Game {
//     constructor(n) {
//         this.name = n;
//     }
//     printName() {
//         console.log(this.name);
//     }
// }

// console.log(typeof Game);
// console.log(Game.prototype.printName)

// function Game(n) {
//     this.name = n;
// }

// Game.prototype.printName = function () {
//     console.log(this.name);
// };

// let g1 = new Game("Chess");
// let g2 = new Game("Football");

// console.log(g1.printName === g2.printName);

// const wizard = {
//     magicNumber: 50,
//     catSpell : ()=>{
//         console.log(this.magicNumber);
//     }
// }
// wizard.catSpell();

// const hero = {
//     name: "Thor",
//     greet: function (){
//         const inner = function (){
//             console.log(`Hello i am ${this.name}`);
//         }
//         inner();
//     }

// }
// hero.greet();

// const wizard = {
//     magicNumber: 42,

//     spell: function(a,b){
//         console.log(`MAgic Boost: ${this.magicNumber}`);
//         return a+b+ this.magicNumber;
//     }
// }
// console.log(wizard.spell(10,5));

// function outer() {
//     let secret = "I am a secret!";
//     return function inner() {
//         console.log(secret);
//     }
// }

// const myClosure = outer();
// myClosure();

// var globalVar = 'global';
// var outerVar = 'outer';

// function outerFunc(outerParam){
//     function innerFunc(innerParam){
//         console.log(globalVar,outerParam,innerParam);
//     }
//     return innerFunc;
// }

// const x = outerFunc(outerVar);
// outerVar = 'outer-2';
// globalVar = 'guess';

// x('inner');

// const arrFuncs = [];
// for (var i = 0; i < 5; i++) {
//     (function (j) {
//         arrFuncs.push(function () {
//             return j;
//         })
//     })(i);
// }

// console.log(i);

// for (let i = 0; i < arrFuncs.length; i++) {
//     console.log(arrFuncs[i]());
// }

// const x = 1;
// const inner = () => {
//     console.log(x);
// }

// const outer = () => {
//     const x = 2;
//     inner();
// }

// outer();

// let a = 10;
// function foo() {
//     console.log(a);
// }

// function bar() {
//     let a = 20;
//     foo();
// }
// bar();

// const x = 1;

// const outer = () => {
//     const x = 2;
//     const inner = () => {
//         debugger;
//         console.log(x);
//     }
//     return inner;
// }
// const foo = outer();
// debugger;
// foo();

// function foo(a){
//     return function (b){
//         return a===b;
//     };
// };
// const isFive = foo(5);
// console.log(isFive(5));
// console.log(isFive(6));

// const isHello = foo("hello");
// console.log(isHello("hello"));
// console.log(isHello("world"));

// const outer = () => {
//     const x = 2;
//     const y = 1;
//     const HUGE = { one: 1, two: 2 };

//     const bar = () => {
//         console.log(HUGE);
//     };
//     const inner = () => {
//         debugger;
//         console.log(x);
//     };
//     return inner;
// };

// const foo = outer();

// foo();

// var f = function (x) {
//     return function (y) { return y - x };
// }

// var g = f(7);
// console.log(g(5));

// var b= 6;
// var foo = function (a){
//     a= b+a;
//     return function(){return a;};
// }

// b=2;
// var bar = function(){
//     var b= 3;
//     return foo(b);
// }

console.log('stack [1]');
setTimeout(() => console.log("macro [2]"), 0);
setTimeout(() => console.log("macro [3]"), 1);
const p = Promise.resolve();
p.then(() => {
setTimeout(() => {
console.log('stack [4]')
setTimeout(() => console.log("macro [5]"), 0);
p.then(() => console.log('micro [6]'));
}, 0);
console.log("stack [7]");
});
console.log("macro [8]");
