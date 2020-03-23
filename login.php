<?php
include 'user_login_check.php';
session_start(); //初始化一个session 
$username=$_POST["username"];  
$password=$_POST["password"]; 
$_session["user"]=$username;

if (userInDB_T($_POST["username"], $_POST["password"]) == true) {
   	setcookie("username", $_POST["username"], time() + (60 * 30), "/"); // 30 minutes
   	setcookie("password", $_POST["password"], time() + (60* 30), "/"); // 30 minutes
	header("Location: http://localhost/update.html");
}
elseif (userInDB_Ad($_POST["username"], $_POST["password"]) == true){
	setcookie("username", $_POST["username"], time() + (60 * 30), "/"); // 30 minutes
   	setcookie("password", $_POST["password"], time() + (60 * 30), "/"); // 30 minutes
	header("Location: http://localhost/maintain.html");
} else {
   	echo("Sorry, incorrect username or password. <br>");
	header("Location: http://localhost/login.html");
}
//session_destroy();
?>
</body>
</html>
