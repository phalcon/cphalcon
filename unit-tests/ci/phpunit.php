<?php

if (!isset($_SERVER['SCRIPT_NAME'])) {
	$_SERVER['SCRIPT_NAME'] = null;
}

define('PHPUnit_MAIN_METHOD', 'PHPUnit_TextUI_Command::main');
require 'vendor/autoload.php';

PHPUnit_TextUI_Command::main();

