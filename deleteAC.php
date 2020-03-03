<?php
    $PW=$UN="";
    $user=$_GET['delete']; 

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
        $sql = "SELECT * FROM teachers";
        $result = $conn->query($sql);
        $count = 0;
        $username="";
        if ($result->rowCount() != 0) {
            while($row = $result -> fetch()) {
                $count ++;
                if($count==$user){
                    // echo"<tr>
                        $UN=$row['userName'];
                        // </tr>"; 
                break;
                }
            }
        }
        $sql = "DELETE from teachers where userName='$UN';";
        $conn->query($sql);
        // $result=$conn->query($sql);
        if ($conn->query($sql) === TRUE) {
            echo "delete successful";
        } else {
                //echo "Error: " . $sql . "<br>" . $conn->error;
        }
        $conn=null;
        header("Location: http://localhost/manageAccount.php");
    } catch (PDOException $e) {
            echo 'Error!: ' . $e->getMessage() . '<br />';
        }  
?>