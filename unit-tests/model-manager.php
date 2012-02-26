<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

$modelsDir = 'tests/models/';

$modelManager = new Phalcon_Model_Manager();
$modelManager->setModelsDir($modelsDir);

if($modelManager->getModelsDir()==$modelsDir){
	echo 'Phalcon_Model_Manager::getModelsDir() [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getModelsDir() [FAILED]', PHP_EOL;
	return false;
}

$isModel = $modelManager->isModel('NoExiste');
if(!$isModel){
	echo 'Phalcon_Model_Manager::isModel() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::isModel() [1] [FAILED]', PHP_EOL;
	return false;
}

$isModel = $modelManager->isModel('Personas');
if($isModel){
	echo 'Phalcon_Model_Manager::isModel() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::isModel() [2] [FAILED]', PHP_EOL;
	return false;
}

$Personas = $modelManager->getModel('Personas');
if(get_class($Personas)=='Personas'){
	echo 'Phalcon_Model_Manager::getModel() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getModel() [1] [FAILED]', PHP_EOL;
	return false;
}

$Prueba = new Prueba($modelManager);
if(get_class($Prueba)=='Prueba'){
	echo 'Phalcon_Model_Manager::getModel() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getModel() [2] [FAILED]', PHP_EOL;
	return false;
}