console.log("Hello worldd");
let randomnum;
randomnum1=Math.floor(Math.random() * 255) + 1;
let randomnum2=Math.floor(Math.random() * 255) + 1;
let randomnum3=Math.floor(Math.random() * 255) + 1;
let randomnum4=Math.floor(Math.random() * 255) + 1;
let randomnum5=Math.floor(Math.random() * 255) + 1;
let randomnum6=Math.floor(Math.random() * 255) + 1;

document.querySelectorAll(".box").forEach(e=>{
    e.style.backgroundColor=`rgb(${randomnum1}, ${randomnum2}, ${randomnum3})`;
    e.style.color=`rgb(${randomnum4}, ${randomnum5}, ${randomnum6})`;

})
// let div=document.createElement("div");
// div.setAttribute("class","created");
// div.innerHTML="Hello I have been created by<b> nats</b>"
// document.querySelector(".container").prepend(div);
let cont=document.querySelector(".container");
cont.insertAdjacentHTML("afterbegin","<b>Hello nats is here</b>");
