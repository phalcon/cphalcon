<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

$config = array(
	'adapter' => 'Mysql',
	'host' => '192.168.0.28',
	'username' => 'support',
	'password' => 'H45pov682v',
	'name' => 'demo'
);

Phalcon_Db_Pool::setDefaultDescriptor($config);
if(Phalcon_Db_Pool::hasDefaultDescriptor()==true){
	echo 'Phalcon_Db_Pool::hasDefaultDescriptor() [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Db_Pool::hasDefaultDescriptor() [FAILED]', PHP_EOL;
}

$modelsDir = 'tests/models/phalcon/';

$modelManager = new Phalcon_Model_Manager();
$modelManager->setModelsDir($modelsDir);

$numPersonas = $modelManager->getModel('Personas')->count();
if($numPersonas>0){
	echo 'Phalcon_Model_Manager::getModel() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getModel() [1] [FAILED]', PHP_EOL;
	return false;
}

try {

	$transaction = Phalcon_Transaction_Manager::get();

	if(get_class($transaction)=='Phalcon_Transaction'){
		echo 'Phalcon_Transaction::get_class() [1] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Transaction::get_class() [1] [FAILED]', PHP_EOL;
	}

	for($i=0;$i<10;$i++){
		$persona = new Personas($modelManager);
		$persona->setTransaction($transaction);
		$persona->cedula = 'T-Cx'.mt_rand(80000, 100000);
		$persona->tipo_documento_id = 1;
		$persona->nombres = 'LOST LOST';
		$persona->telefono = '2';
		$persona->cupo = 0;
		$persona->estado = 'T';
		if($persona->save()==false){
			echo 'Phalcon_Model_Base::save() [FAILED]', PHP_EOL;
			return false;
		}
	}

	$transaction->rollback();

}
catch(Phalcon_Transaction_Failed $e){
	$rollbackNumPersonas = $modelManager->getModel('Personas')->count();
	if($numPersonas==$rollbackNumPersonas){
		echo 'Phalcon_Transaction::rollback() [1] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Transaction::rollback() [1] [FAILED]', PHP_EOL;
		return false;
	}
}

try {

	$transaction = Phalcon_Transaction_Manager::get();

	if(get_class($transaction)=='Phalcon_Transaction'){
		echo 'Phalcon_Transaction::get_class() [2] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Transaction::get_class() [2] [FAILED]', PHP_EOL;
	}

	for($i=0;$i<15;$i++){
		$persona = new Personas($modelManager);
		$persona->setTransaction($transaction);
		$persona->cedula = 'T-Cx'.mt_rand(80000, 100000);
		$persona->tipo_documento_id = 1;
		$persona->nombres = 'LOST LOST';
		$persona->telefono = '1';
		$persona->cupo = 0;
		$persona->estado = 'T';
		if($persona->save()==false){
			echo 'Phalcon_Model_Base::save() [2] [FAILED]', PHP_EOL;
			return false;
		}
	}

	$transaction->commit();

	$commitNumPersonas = $modelManager->getModel('Personas')->count();
	if($commitNumPersonas==($numPersonas+15)){
		echo 'Phalcon_Transaction::commit() [1] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Transaction::commit() [1] [FAILED]', PHP_EOL;
	}

}
catch(Phalcon_Transaction_Failed $e){

}