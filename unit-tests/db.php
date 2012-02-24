<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

require 'tests/autoload.php';

$config = new stdClass();
$config->host = '192.168.0.20';
$config->username = 'support';
$config->password = 'H45pov682v';
$config->name = 'demo';

try {

	$connection = Phalcon_Db::factory('Mysql', $config, true);

	if($connection->getDatabaseName()==$config->name){
		echo 'Phalcon_Db::getDatabaseName() [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::getDatabaseName() [FAILED]', PHP_EOL;
		return false;
	}

	if($connection->getHostname()==$config->host){
		echo 'Phalcon_Db::getHostname() [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::getHostname() [FAILED]', PHP_EOL;
		return false;
	}

	if($connection->getUsername()==$config->username){
		echo 'Phalcon_Db::getUsername() [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::getUsername() [FAILED]', PHP_EOL;
		return false;
	}

	if($connection->getDefaultSchema()==$config->name){
		echo 'Phalcon_Db::getDefaultSchema() [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::getDefaultSchema() [FAILED]', PHP_EOL;
		return false;
	}

	$result = $connection->query("SELECT * FROM personas LIMIT 3");
	if(!is_resource($result)){
		echo 'Phalcon_Db::query() [1] [FAILED]', PHP_EOL;
		return false;
	} else {
		echo 'Phalcon_Db::query() [1] [OK]', PHP_EOL;
	}

	for($i=0;$i<3;$i++){
		$row = $connection->fetchArray($result);
		if(count($row)!=22){
			echo 'Phalcon_Db::fetchArray() standard [FAILED]', PHP_EOL;
			return false;
		} else {
			echo 'Phalcon_Db::fetchArray() standard [OK]', PHP_EOL;
		}
	}

	$row = $connection->fetchArray($result);
	if($row!==false){
		echo 'Phalcon_Db::fetchArray() standard [FAILED]', PHP_EOL;
		return false;
	} else {
		echo 'Phalcon_Db::fetchArray() standard [OK]', PHP_EOL;
	}

	if($connection->numRows($result)!=3){
		echo 'Phalcon_Db::numRows() standard [FAILED]', PHP_EOL;
		return false;
	} else {
		echo 'Phalcon_Db::numRows() standard [OK]', PHP_EOL;
	}

	$number = 0;
	$result = $connection->query("SELECT * FROM personas LIMIT 5");
	if(!is_resource($result)){
		echo 'Phalcon_Db::query() [2] [FAILED]', PHP_EOL;
		return false;
	} else {
		echo 'Phalcon_Db::query() [2] [OK]', PHP_EOL;
	}

	while($row = $connection->fetchArray($result)){
		$number++;
	}

	if($number!=5){
		echo 'Phalcon_Db::fetchArray() [2] [FAILED]', PHP_EOL;
		return false;
	} else {
		echo 'Phalcon_Db::fetchArray() [2] [OK]', PHP_EOL;
	}

	$connection->setFetchMode(Phalcon_Db::DB_NUM);
	$result = $connection->query("SELECT * FROM personas LIMIT 5");
	$row = $connection->fetchArray($result);
	if(count($row)!=11){
		echo 'Phalcon_Db::fetchArray() [3] [FAILED]', PHP_EOL;
		return false;
	} else {
		echo 'Phalcon_Db::fetchArray() [3] [OK]', PHP_EOL;
	}

	$connection->setFetchMode(Phalcon_Db::DB_ASSOC);
	$result = $connection->query("SELECT * FROM personas LIMIT 5");
	$row = $connection->fetchArray($result);
	if(count($row)!=11){
		echo 'Phalcon_Db::fetchArray() [4] [FAILED]', PHP_EOL;
		return false;
	} else {
		echo 'Phalcon_Db::fetchArray() [4] [OK]', PHP_EOL;
	}

	$connection->setFetchMode(Phalcon_Db::DB_BOTH);
	$result = $connection->query("SELECT * FROM personas LIMIT 5");
	$connection->dataSeek(4, $result);
	$row = $connection->fetchArray($result);
	$row = $connection->fetchArray($result);
	if($row!==false){
		echo 'Phalcon_Db::fetchArray() [5] [FAILED]', PHP_EOL;
		return false;
	} else {
		echo 'Phalcon_Db::fetchArray() [5] [OK]', PHP_EOL;
	}

	$result = $connection->query("DELETE FROM prueba");
	if($result){
		echo 'Phalcon_Db::query() [3] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::query() [3] [FAILED]', PHP_EOL;
		return false;
	}

	$success = $connection->insert('prueba', array('null', "'LOL 1'", "'A'"));
	if($success){
		echo 'Phalcon_Db::insert() [4] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::insert()) [4] [FAILED]', PHP_EOL;
		return false;
	}

	$success = $connection->insert('prueba', array("'LOL 2'", "'E'"), array('nombre', 'estado'));
	if($success){
		echo 'Phalcon_Db::insert() [5] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::insert() [5] [FAILED]', PHP_EOL;
		return false;
	}

	$success = $connection->insert('prueba', array("LOL 3", "I"), array('nombre', 'estado'), true);
	if($success){
		echo 'Phalcon_Db::insert() [6] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::insert() [6] [FAILED]', PHP_EOL;
		return false;
	}

	$success = $connection->insert('prueba', array(new Phalcon_Db_RawValue('current_date'), "'A'"), array('nombre', 'estado'));
	if($success){
		echo 'Phalcon_Db::insert() [7] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::insert() [7] [FAILED]', PHP_EOL;
		return false;
	}

	for($i=0;$i<50;$i++){
		$success = $connection->insert('prueba', array("LOL ".$i, "F"), array('nombre', 'estado'), true);
		if(!$success){
			echo 'Phalcon_Db::insert() ['.($i+8).'] [FAILED]', PHP_EOL;
			return false;
		}
	}
	echo 'Phalcon_Db::query() multiple ['.($i+8).'] [OK]', PHP_EOL;

	$success = $connection->update('prueba', array("nombre", "estado"), array("'LOL 1000'", "'X'"), "estado='E'");
	if($success){
		echo 'Phalcon_Db::update() [1] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::update() [1] [FAILED]', PHP_EOL;
		return false;
	}

	$success = $connection->update('prueba', array("nombre"), array("'LOL 2500'"), "estado='X'");
	if($success){
		echo 'Phalcon_Db::update() [2] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::update() [2] [FAILED]', PHP_EOL;
		return false;
	}

	$success = $connection->update('prueba', array("nombre"), array("LOL 3000"), "estado='X'", true);
	if($success){
		echo 'Phalcon_Db::update() [3] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::update() [3] [FAILED]', PHP_EOL;
		return false;
	}

	$success = $connection->update('prueba', array("nombre"), array(new Phalcon_Db_RawValue('current_date')), "estado='X'", false);
	if($success){
		echo 'Phalcon_Db::update() [4] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::update() [4] [FAILED]', PHP_EOL;
		return false;
	}

	$connection->delete("prueba", "estado='X'");
	if($success){
		echo 'Phalcon_Db::delete() [1] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::delete() [1] [FAILED]', PHP_EOL;
		return false;
	}

	$connection->delete("prueba");
	if($success){
		echo 'Phalcon_Db::delete() [2] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Db::delete() [2] [FAILED]', PHP_EOL;
		return false;
	}

}
catch(Phalcon_Db_Exception $e){
	echo 'Phalcon_Db::factory [FAILED] ', $e->getMessage(), PHP_EOL;
}
