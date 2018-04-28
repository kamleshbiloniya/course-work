//function myFunction() {
    var x = document.getElementById("myInput6").value;
    if (x.type === "password") {
        x.type = "text";
    } else {
        x.type = "password";
    }
}

//function functionName() {
  var x = document.myform.name.value;
  if(x==null){
    document.getElementById("idone").innerHTML = "Invalid name";
  }
  else{
    document.getElementById("idone").innerHTML = "Hello word";
  }
}
//document.getElementById("idone").innerHTML = "Hello word";
function validationForm() {
    var x = document.forms["myform"]["name"].value;
    if (x === ""||/d/.test(x) || x.length >20) {
      document.getElementById('nameid').innerHTML="Invalid name";
        return false;
    }
    var add=document.forms["myform"]["address"].value;
    if(add==="" || x.length >100){
      document.getElementById('addid').innerHTML="Address too long or empty";
      return false;
    }
    var email=document.forms["myform"]["email"].value;
    if(email===""||/[^a-z]+@/.test(email) ||/@[^a-z]+\.com/.test(email)){
    document.getElementById('emailid').innerHTML="Invalid email address";
    return false;
  }
    var mobile=document.forms["myform"]["mobile"].value;
    if(mobile===""||/[^1-9][0-9]{9}/.test(mobile)){
      document.getElementById('mobileid').innerHTML="Please enter valid mobile number";
      return false;
    }
    var ac=document.forms["myform"]["acnumber"].value;
    if(ac===""||/[^0-9]{5}/.test(ac)){
      document.getElementById('acid').innerHTML="Invalid account number";
      return false;
    }
    var pass=document.forms["myform"]["passwd"].value;
    if(pass===""||pass.length>20){
      document.getElementById('passid').innerHTML="too long passwd";
      return false;
    }
    return true;
}
