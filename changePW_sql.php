<?php
    $PW=$UN="";
    $UN=$_GET['user'];
    $PW=$_POST['password']; 

    $servername = "localhost:3307";
    $username = "root";
    $password = "";
    $dbname = "cbot_users";

    // create a link
    try {
        $conn = new PDO("mysql:host=localhost:3307;dbname=cbot_users",
                "root", "");
        $conn->setAttribute(PDO::ATTR_ERRMODE,
        PDO::ERRMODE_EXCEPTION);

        $sql = "UPDATE teachers SET userPassword='$PW' where userName='$UN';";
        $conn->query($sql);
        // $result=$conn->query($sql);
        if ($conn->query($sql) === TRUE) {
            echo "insert successful";
        } else {
                //echo "Error: " . $sql . "<br>" . $conn->error;
        }
        $conn=null;
        header("Location: http://localhost/manageAccount.php");
    } catch (PDOException $e) {
            echo 'Error!: ' . $e->getMessage() . '<br />';
        }  
?>