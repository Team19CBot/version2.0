<!DOCTYPE html>
      <head>
            <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
            <title>CBot-maintain-ExistingAccount</title>
            <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico"/>
            <bookmark href="/favicon.ico"/>
            <link rel="stylesheet" href="/maintain.css">
            <script type="text/javascript" src="/checkCookieA.php"></script> 
      </head>
      <body>
            <script>
                function jumpToC(count){
                    window.location.href="changePW.php?change="+count;
                }
                function jumpToD(count){
                    var flag = confirm("Do you really want to delete this account?");
                    if (flag == true){//delete
                        window.location.href="deleteAC.php?delete="+count;                        
                    }
                }
            </script>
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
                            <a href="http://localhost/addKeywords.html" rel="noopener noreferrer">Add Synonymous keywords</a>  
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
                        <header1>Manage The Accounts Of Our CBot System</header1>
                        <table border="5">
                            <tr>
                                <th> Username </th>
                                <th> Password </th>
                                <th> Modify Password </th>
                                <th> Logoff </th>
                            </tr>
                            <?php
                                try {
                                    $conn = new PDO("mysql:host=localhost:3307;dbname=cbot_users",
                                                    "root", "");
                                    $conn->setAttribute(PDO::ATTR_ERRMODE,
                                                        PDO::ERRMODE_EXCEPTION);
                                    $sql = "SELECT * FROM teachers";
                                    $result = $conn->query($sql);
                                    $conn = NULL;
                                    $count = 0;
                                    if ($result->rowCount() != 0) {
                                        while($row = $result -> fetch()) {
                                            $count ++;
                                            echo    "<tr>
                                                        <td>" . $row['userName'] . "</td>
                                                        <td>" . $row['userPassword'] . "</td>
                                                        <td>" . "<button id=\"manageAccounts\" onclick=\"jumpToC($count)\" >Change</button>" . "</td>
                                                        <td><button  onclick=\"jumpToD($count)\" id=\"manageAccounts\">Delete</button></td>
                                                    </tr>"; 
                                        }
                                        echo "<tr>
                                                    <th>Total</th> 
                                                    <th>" . $count . "</th>
                                                    <th></th>
                                                    <th></th>
                                             </tr>";
                                    } else {
                                        echo "Ops! No Accounts In Our Database";
                                    }
                                } catch (PDOException $e) {
                                    echo 'Error!: ' . $e->getMessage() . '<br />';
                                }  
                            ?> 
                        </table>
                    </div>
                </div>
            </div> 
      </body>
</html>