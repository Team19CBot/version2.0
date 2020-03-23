<?php
include 'user_login_check.php';

if (checkLoggedInA() == true || checkLoggedInT() == true) {
    //login done
}
else{
    echo "window.location.href=\"http://localhost/login.html\";";
}

?> 