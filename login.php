<?php
include 'user_login_check.php';
session_start(); //初始化一个session 
$_session["user"]="user";
$username=$_POST["username"];  
$password=$_POST["password"]; 

if (userInDB_T($_POST["username"], $_POST["password"]) == true) {
   	setcookie("username", $_POST["username"], time() + (86400 * 30), "/"); // 86400 = 1 day
   	setcookie("password", $_POST["password"], time() + (86400 * 30), "/"); // 86400 = 1 day
	header("Location: http://localhost/update.html");
}
elseif (userInDB_Ad($_POST["username"], $_POST["password"]) == true){
	setcookie("username", $_POST["username"], time() + (86400 * 30), "/"); // 86400 = 1 day
   	setcookie("password", $_POST["password"], time() + (86400 * 30), "/"); // 86400 = 1 day
	header("Location: http://localhost/maintain.html");
} else {
   	echo("Sorry, incorrect username or password. <br>");
	header("Location: http://localhost/login.html");
}
//session_destroy();
?>
</body>
</html>
