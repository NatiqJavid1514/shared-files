console.log("Hello world")
document.body.childNodes/* this is for all the child nodes including texts*/
document.body.childNodes[0]/* This is to select the first ChildNode which displayed*/
let cont=document.body.childNodes[3]/* This meanss the third child node is now a constant and is now easily accessble*/

/* Now if we want to only the element child nodes as text comment nodes also come under (only) child nodes.  We will do firstelement or last element child node*/

document.body.firstElementChild
document.body.lastElementChild
//  now we can change styles of all the elements by document.body.firstElementChild.style.backgroundColor="red"

// To display all the children (that are Elements)
document.body.firstElementChild.children

//I can also get to what is the next element sibling of a particular element by://
document.body.firstElementChild.nextElementSibling
// same goes to previous element sibling//
//if I write only sibling I can get text node as well as text node lies in all nodes//
