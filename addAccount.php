<!DOCTYPE html>
      <head>
            <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
            <title>CBot-maintain-NewAccount</title>
            <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico"/>
            <bookmark href="/favicon.ico"/>
            <link rel="stylesheet" href="/maintain.css">
            <script type="text/javascript" src="/checkCookieA.php"></script> 
        </head>
      <body>
            <div class = "navigation_bar">
                <a href="cbot" rel="noopener noreferrer">CBot</a>
                <a href="http://localhost/update.html" rel="noopener noreferrer">UPDATE</a>
                <a href="http://localhost/maintain.html" rel="noopener noreferrer">MAINTAIN</a>
                <textarea name=search placeholder="Search for datebase or users information"></textarea>
                <button name="search"></button>
                <!-- <div>Admin</div> -->
            </div>
            <div class="layer">
                <div class="leftP">
                <ul>
                        <li>
                            <a href="http://localhost/maintain.html" rel="noopener noreferrer">Dashboard</a>   
                        </li>
                        <li id="second">
                            <a href="http://localhost/maintain.html" rel="noopener noreferrer">Manage Questions</a>  
                            <ul>
                                <!-- <li>
                                    <a href="http://localhost/allQuestions.html" rel="noopener noreferrer">All Questions</a>  
                                </li> -->
                                <li>
                                    <a href="http://localhost/queryQuestions.html" rel="noopener noreferrer">Query Quesions</a>  
                                </li>
                                <li>
                                    <a href="http://localhost/addQuestions.html" rel="noopener noreferrer">Add Questions</a>  
                                </li>
                                <li>
                                    <a href="http://localhost/deleteQuestions.html" rel="noopener noreferrer">Delete Questions</a>  
                                </li>
                                <li>
                                    <a href="http://localhost/modifyQuestions.html" rel="noopener noreferrer">Modify Questions</a>  
                                </li>
                            </ul> 
                        </li>
                        <li>
                            <a href="http://localhost/addQuestions.html" rel="noopener noreferrer">Add Synonymous keywords</a>  
                        </li>
                        <li id="second">
                            <a href="http://localhost/maintain.html" rel="noopener noreferrer">Teachers' Accounts</a>
                            <ul>
                                <li>
                                    <a href="http://localhost/addAccount.html" rel="noopener noreferrer">Add New Accounts</a>  
                                </li>
                                <li>
                                    <a href="http://localhost/manageAccount.php" rel="noopener noreferrer">Manage Existing Accounts</a>  
                                </li>
                            </ul> 
                        </li>
                    </ul>
                </div>
                <div class="rightP">
                    <div>
                        <header1>Add A New Account For Our CBot System</header1>
                        <form action="addAccount.php" method="post">
                            <table border="5" style="margin-top: 40px; width: 50%; margin-left: 25%; height: 250px;">
                                <tr style="height: 20%;">
                                    <th> 
                                        Username 
                                    </th>
                                </tr>
                                <tr>
                                    <th><input style="height: 65%;" type="text" name="username" required=""></th>
                                </tr>
                                <tr>
                                    <th> Password </th>
                                </tr>
                                <tr>
                                    <th><input style="height: 65%;" type="text" name="password" required=""></th>
                                </tr>
                            </table>
                            <input type="submit" name="" value="Register">
                        </form>
                        <?php
                            $UN=$PW="";
                            $UN=$_POST['username'];
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
                                $sql = "SELECT * FROM teachers where userName = '$UN';";
                                $result = $conn->query($sql);
                                if ($result->rowCount() != 0) {
                                    $flag = 0;//no same account
                                } else {
                                    $flag=1;
                                }

                                if ($flag == 1)
                                {
                                    echo '<script>alert("register successful")</script>';
                                    $sql2 = "INSERT INTO teachers (userName, userPassword)
                                    VALUES ('$UN', '$PW')";
                                    // $conn->exec($sql2);
                                    $conn->query($sql2);
                                    // $result=$conn->query($sql);
                                    if ($conn->query($sql) === TRUE) {
                                        echo "insert successful";
                                    } else {
                                        //echo "Error: " . $sql . "<br>" . $conn->error;
                                    }
                                }
                                else{
                                    echo '<script>alert("register fail");</script>';
                                } 
                                $conn=null;
                            } catch (PDOException $e) {
                                echo 'Error!: ' . $e->getMessage() . '<br />';
                            }  
                        ?>
                    </div>
                </div>
            </div>
      </body>
</html>