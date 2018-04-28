<!DOCTYPE html>
<html>
<body>
<head>
<link href="style.css" rel="stylesheet" type="text/css">
 <script src="myscripts.js"></script>
</head>
<h2>Lets build stuff!</h2>
<p>Please fill following registration form to participate in Summer Dance practice</p>
<p><span class="error">* required field.</span></p>

<form method="post" name="myform" action="" onsubmit="return validationForm()" >
  <fieldset >

Full name:<input type="text" name="name" maxlength="20" id="myInput1">
<span class="error" id="nameid">*</span>
<br><br>
<p>Address:</p><textarea name="address" rows="4" cols="50" maxlength="10" id="myInput"></textarea>
<span class="error" id="addid">*</span>
<br><br>
E-mail: <input type="text" name="email" id="myInput" >
<span class="error" id="emailid">* <?php echo $emailErr;?></span><br><br>
Mobile:<input type="number" name="mobile" maxlength="10" id="myInput" >
<span class="error" id="mobileid">* <?php echo $mobileErr;?></span><br><br>
Account number:<input type="number" name="acnumber" id="myInput" >
<span class="error" id="acid">* <?php echo $acnumberErr;?></span><br><br>
Password: <input type="password" name="passwd" id="myInput6" >
<span class="error" id="passid">* <?php echo $passwdErr;?></span><br><br>
<input type="checkbox" onclick="myFunction()">Show Password<br><br>
<input type="submit" name="submit" value="submit">
<input type="reset" value="Clear">
</fieldset >

</form>
<!-- <button type="button" formaction="admin.html" style="width:auto;">See all registrations</button> -->
<a href="admin.html">See all registrations</a>

</body>
</html>
