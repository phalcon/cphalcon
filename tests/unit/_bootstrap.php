<?php
// Here you can initialize variables that will be available to your tests

define('ROOT_PATH', dirname(dirname(__FILE__)));
define('UNIT_TESTING', true);

// loading verify assert BDD style assert
require_once ROOT_PATH . '/_support/Verify.php';

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
