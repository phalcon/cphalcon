<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

require 'tests/autoload.php';

$config = array(
	'adapter' => 'Mysql',
	'host' => '192.168.0.20',
	'username' => 'support',
	'password' => 'H45pov682v',
	'name' => 'demo'
);

Php_Db_Pool::setDefaultDescriptor($config);
if(Php_Db_Pool::hasDefaultDescriptor()==true){
	echo 'php Db_Pool has default descriptor [OK]', PHP_EOL;
} else {
	echo 'php Db_Pool has default descriptor [FAILED]', PHP_EOL;
}

Phalcon_Db_Pool::setDefaultDescriptor($config);
if(Phalcon_Db_Pool::hasDefaultDescriptor()==true){
	echo 'c Db_Pool has default descriptor [OK]', PHP_EOL;
} else {
	echo 'c Db_Pool has default descriptor [FAILED]', PHP_EOL;
}

$connection = Php_Db_Pool::getConnection();
if(is_object($connection)){
	echo 'Php_Db_Pool::getConnection [1] [OK]', PHP_EOL;
} else {
	echo 'Php_Db_Pool::getConnection [1] [FAILED]', PHP_EOL;
}

$connection = Phalcon_Db_Pool::getConnection();
if(is_object($connection)){
	echo 'Phalcon_Db_Pool::getConnection [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Db_Pool::getConnection [2] [FAILED]', PHP_EOL;
}

$connection2 = Php_Db_Pool::getConnection(true);
if($connection->getConnectionId()!=$connection2->getConnectionId()){
	echo 'Php_Db_Pool::getConnection [2] [OK]', PHP_EOL;
} else {
	echo 'Php_Db_Pool::getConnection [2] [FAILED]', PHP_EOL;
}

$connection2 = Phalcon_Db_Pool::getConnection(true);
if($connection->getConnectionId()!=$connection2->getConnectionId()){
	echo 'Phalcon_Db_Pool::getConnection [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Db_Pool::getConnection [2] [FAILED]', PHP_EOL;
}