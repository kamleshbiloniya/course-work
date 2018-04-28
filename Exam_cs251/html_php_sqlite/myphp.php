<?php

// define variables and set to empty values
$name = $email = $gender = $comment = $website = "";
//$dbhandle = sqlite_open('info.db', 0666, $error);
$db = new SQLite3('info.db');
class MyDB extends SQLite3 {
       function __construct() {
          $this->open('info.db');
       }
    }
  //  $db = new MyDB();
    if(!$db) {
       echo $db->lastErrorMsg();
    } else {
       echo "Opened database successfully\n";
    }

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $name = test_input($_POST["name"]);
  $address = test_input($_POST["address"]);
  $email = test_input($_POST["email"]);
  $mobile = test_input($_POST["mobile"]);
  $acnumber = test_input($_POST["acnumber"]);
  $passwd = test_input($_POST["passwd"]);
  $qstr = "INSERT INTO info(name,address,email,mobile,account_no,password) VALUES ('$name','$address', '$email', $mobile,$acnumber,'$passwd')";
  //$insres =sqlite_exec($dbhandle,$qstr);
   $insres = $db->query($qstr);
   echo "$insres";
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>
