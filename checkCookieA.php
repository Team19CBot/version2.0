<?php
include 'user_login_check.php';

if (checkLoggedInA() == true) {
    //login done
}
else{
    echo "window.location.href=\"http://localhost/login.html\";";
}

?> 