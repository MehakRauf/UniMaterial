// const d = document.getElementsByClassName('hello')[0];
// console.log(d.contains("hello"))
// let p = document.getElementsByTagName('div')[0]
// let q = document.querySelector(".hello")
// let id = document.getElementById("h1")
// let qp = document.querySelector("#h1");
// console.log(qp);
// console.log(id);
// console.log(q);
// console.log(p);
// console.log(d);

// let b = document.body.previousSibling;
// console.log(b);
// console.log(b.hasChildNodes())


// elem.matches(css) // matches the given the css
// elem.closest(css) // look for a nearest ancestor that matches the given css selector
// elem.contains(elemB) // returns true if elemB is inside elemA or elem==elemB

// hasAttribute, getAttribute, removeAttribute, setAttribute('name','value'), .attributes

// let p = document.createElement('div');
// p.innerHTML = "<h1>Hello World</h1>";

// d.classList.add("h1");
// console.log(d);

// d.classList.toggle("h1");
// console.log(d);

// d.classList.remove("hello");
// console.log(d)

// d.addEventListener("click", () => {
//     d.after(p);
// })

// d.removeEventListener("click",()=>{
//     d.after(p);
// })

// setTimeout(() => {
//     console.log("Hello")
// }, 1000);
// setInterval(() => {
//     console.log("Hello")
// }, 1000);

// const arr = [1, 2, 3, 4];
// const [first, ...rest1] = arr;

// const obj = {
//     name: "Mehak Fatima",
//     "2": "Kainat",
//     "3": "Tahrim"
// };

// const { name, ...rest } = obj;
// console.log(name)
// console.log(rest)

// const o = { "name": "Mehak", "class": "4th-year" };
// const o1 = { ...o, "Age": 21 };
// console.log(o1);
// console.log(o);

// setTimeout(() => {
//     console.log("H1")
//     setTimeout(() => {
//         console.log("H2")
//         setTimeout(() => {
//             console.log("H3")
//             setTimeout(() => {
//                 console.log("H4")
//                 setTimeout(() => {
//                     console.log("H5")
//                 }, 1000)
//             }, 1000)
//         }, 1000)
//     }, 1000)
// }, 1000);

// let p = new Promise((resolve, reject) => {
//     let success = true;
//     if (success) {
//         resolve("Promise resolved");
//     } else {
//         reject("Promise rejected");
//     }
// });

// p.then((msg) => {
//     console.log(msg);
// }).catch((err) => {
//     console.log(err);
// });

// function myPromise() {
//     return new Promise((resolve, reject) => {
//         let success = true;
//         if (success) {
//             resolve("Resolved");
//         } else {
//             reject("Rejected");
//         }
//     })
// }

// async function runAsync() {
//     try {
//         const result = await myPromise();
//         console.log("Success:", result);
//     } catch (error) {
//         console.log("Error:", error);
//     }
// }

// // runAsync();
// const p1 = new Promise((resolve) => setTimeout(() => resolve("✅ p1 resolved"), 1000));
// const p2 = new Promise((resolve) => setTimeout(() => resolve("✅ p2 resolved"), 2000));
// const p3 = new Promise((_, reject) => setTimeout(() => reject("❌ p3 rejected"), 1500));

// // Promise.all
// Promise.all([p1, p2])
//   .then(results => console.log("Promise.all results:", results))
//   .catch(error => console.log("Promise.all error:", error));

// // Promise.race
// Promise.race([p1, p2, p3])
//   .then(result => console.log("Promise.race result:", result))
//   .catch(error => console.log("Promise.race error:", error));

// // Promise.allSettled
// Promise.allSettled([p1, p2, p3])
//   .then(results => {
//     console.log("Promise.allSettled results:");
//     results.forEach((res, i) => console.log(`  p${i + 1}:`, res));
//   });

// // Promise.any
// Promise.any([p3]) // Only one promise, and it rejects
//   .then(result => console.log("Promise.any result:", result))
//   .catch(error => {
//     console.log("Promise.any error:", error);
//   });

