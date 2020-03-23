<?php
function checkLoggedInT()
{
	if (isset($_COOKIE["username"]) && isset($_COOKIE["password"])) {
		return userInDB_T($_COOKIE["username"], $_COOKIE["password"]);
	} else {
		return false;
	}
}

function checkLoggedInA()
{
	if (isset($_COOKIE["username"]) && isset($_COOKIE["password"])) {
		return userInDB_Ad($_COOKIE["username"], $_COOKIE["password"]);
	} else {
		return false;
	}
}

//check for teachers
function userInDB_T($username, $password)
{
	try {
		$conn = new PDO("mysql:host=localhost:3307;dbname=cbot_users",
						"root", "");
		$conn->setAttribute(PDO::ATTR_ERRMODE,
							PDO::ERRMODE_EXCEPTION);
		$sql = "SELECT * FROM teachers WHERE username = '$username' AND userpassword = '$password';";
		$rows = $conn->query($sql);
		$conn = NULL;
		if ($rows->rowCount() != 0) {
			return true;
		} else {
			return false;
		}
	} catch (PDOException $e) {
		echo 'Error!: ' . $e->getMessage() . '<br />';
	}
}

//check for admin
function userInDB_Ad($username, $password)
{
	try {
		$conn = new PDO("mysql:host=localhost:3307;dbname=cbot_users",
						"root", "");
		$conn->setAttribute(PDO::ATTR_ERRMODE,
							PDO::ERRMODE_EXCEPTION);
		$sql = "SELECT * FROM the_admin WHERE username = '$username' AND userpassword = '$password';";
		$rows = $conn->query($sql);
		$conn = NULL;
		if ($rows->rowCount() != 0) {
			return true;
		} else {
			return false;
		}
	} catch (PDOException $e) {
		echo 'Error!: ' . $e->getMessage() . '<br />';
	}
}


?>