// class Game{
//     constructor(n){
//         this.name=n;
//     }
//     printName(){
//         console.log(this.name);
//     }
// }

// let g1 = new Game("Chess");
// let g2 = new Game("Football");

// console.log(g1.printName == g2.printName);

// class Game {
//     Game(n) {
//         console.log("Game method called!");
//         this.name = n;
//     }
//     printName() {
//         console.log(this.name);
//     }
// }

// let g1 = new Game("Chess");
// let g2 = new Game("Football");

// // console.log(g1.printName == g2.printName);
// g1.printName();

// class Game{
//     constructor(n){
//         this.name = n;
//     }

//     printName(){
//         console.log(this.name);
//     }
// }

// console.log(typeof Game);
// console.log(Game.prototype.printName);


// function Game(n) {
//     this.name = n;
//     this.printName = function () {
//         console.log(this.name);
//     }
// }

// let g1 = new Game("Chess");
// let g2 = new Game("Football");

// console.log(g1.printName === g2.printName);

// function Game(n) {
//     this.name = n;
// }

// Game.prototype.printName = function () {
//     console.log(this.name);
// }

// let g1 = new Game("Chess");
// let g2 = new Game("Football");

// console.log(g1.printName === g2.printName);


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