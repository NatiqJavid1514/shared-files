console.log("HELLO WORLD")
function data(){
    let a=document.getElementById("USERNAME").value;
    let b=document.getElementById("ph").value;
    let c=document.getElementById("email").value;
    let d=document.getElementById("pw").value;
    let emailpattern=/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    let passwordpattern = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;

    if(a==""|| b==""|| c==""|| d==""){
        alert("All entries must be filled.")
        return false;
    }
    else if(isNaN(b)){
        alert("Phone number must contain numbers only and must be 10digit valid")
        return false;
    }
    else if(b.length!=10){
        alert("Phone number should be of 10 digits")
        return false;
    }
    else if(!emailpattern.test(c)){
        alert("Enter a valid email ")
        return false;

    }
    else if(!passwordpattern.test(d)){
        alert("PASSWORD SHOULD BE SRONG AND MUST CONTAINALPHANUMERIC")
        return false;
    }
    else{
       return  true;
    }

    
    
    
}
