<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

require 'tests/autoload.php';

$message = 'sample message';
if(Phalcon_Flash::error($message)==Php_Flash::error($message)){
	echo 'Phalcon_Flash::error [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Flash::error [FAILED]', PHP_EOL;
	return false;
}

if(Phalcon_Flash::success($message)==Php_Flash::success($message)){
	echo 'Phalcon_Flash::success [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Flash::success [FAILED]', PHP_EOL;
	return false;
}

if(Phalcon_Flash::notice($message)==Php_Flash::notice($message)){
	echo 'Phalcon_Flash::notice [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Flash::notice [FAILED]', PHP_EOL;
	return false;
}