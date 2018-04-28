<!DOCTYPE html>
<html>
<head>
</head>
<body>
  <?php

  class MyDB extends SQLite3 {
     function __construct() {
        $this->open('info.db');
     }
  }
  $db = new MyDB();
  if(!$db) {
     echo $db->lastErrorMsg();
  } else {
     echo "Opened database successfully\n";
  }
  $results = $db->query('SELECT * FROM info');
  while ($row = $results->fetchArray()) {
    $var1= $row[0];
    $var2= $row[1];
    $var3= $row[2];
    $var4= $row[3];
    $var5= $row[4];

  }

   ?>

  <p>All records:</p>
  <table id="myTable">
    <tr>
      <th>Name</th>
      <th>Address</th>
      <th>Email</th>
      <th>Mobile</th>
      <th>Account_Number</th>
    </tr>
  <tr id="repeat">
    <td id="1"><?php echo "$var1"?></td>
    <td id="2"><?php echo "$var2"?></td>
    <td id="3"><?php echo "$var3"?></td>
    <td id="4"><?php echo "$var4"?></td>
    <td id="5"><?php echo "$var5"?></td>
  </tr>
  <tr id="repeat">
    <td id="1"><?php echo "$var1"?></td>
    <td id="2"><?php echo "$var2"?></td>
    <td id="3"><?php echo "$var3"?></td>
    <td id="4"><?php echo "$var4"?></td>
    <td id="5"><?php echo "$var5"?></td>
  </tr>
</table>
<br>
<script>
  function myFunction(){
    var table=document.getElementById("myTable");
    var row=table.insertRow(0);
     var row = table.insertRow(1);
      var row = table.insertRow(2);
       var row = table.insertRow(3);
       var row = table.insertRow(4);
       var row = table.insertRow(5);
       window.alert(5 + 6);
  }
</script>


<a href="index.php">Another Registration</a>
</body>
</html>
