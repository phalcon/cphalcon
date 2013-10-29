<?php
// loading verify assert BDD style assert
require_once __DIR__.'/_helpers/Verify.php';

function expect($description, $actual = null)
 {
     return new Codeception\Verify($description, $actual);
 }

function expect_that($truth)
{
    expect($truth)->notEmpty();
}

function expect_not($fallacy)
{
    expect($fallacy)->isEmpty();
}

