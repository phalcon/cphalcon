<?php

//Required for run in GDB
if (PHP_OS=='Linux') {
	if ($_SERVER['USERNAME']=='gutierrezandresfelipe') {
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

$config = array(
	'adapter' => 'Mysql',
	'host' => '192.168.0.25',
	'username' => 'support',
	'password' => 'H45pov682v',
	'name' => 'demo'
);

Phalcon_Db_Pool::setDefaultDescriptor($config);
if(Phalcon_Db_Pool::hasDefaultDescriptor()==true){
	echo 'Phalcon_Db_Pool::hasDefaultDescriptor() [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Db_Pool::hasDefaultDescriptor() [FAILED]', PHP_EOL;
	return false;
}

$manager = new Phalcon_Model_Manager();
$manager->setModelsDir('tests/models/phalcon/');

$success = $manager->load('Robots');
if($success==true){
	echo 'Phalcon_Model_Manager::loadModel() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::loadModel() [1] [FAILED]', PHP_EOL;
}

$manager->load('Parts');
if($success==true){
	echo 'Phalcon_Model_Manager::loadModel() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::loadModel() [2] [FAILED]', PHP_EOL;
}

$manager->load('RobotsParts');
if($success==true){
	echo 'Phalcon_Model_Manager::loadModel() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::loadModel() [3] [FAILED]', PHP_EOL;
}

$success = $manager->existsBelongsTo('RobotsParts', 'Robots');
if($success==true){
	echo 'Phalcon_Model_Manager::existsBelongsTo() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::existsBelongsTo() [1] [FAILED]', PHP_EOL;
}

$success = $manager->existsBelongsTo('RobotsParts', 'Parts');
if($success==true){
	echo 'Phalcon_Model_Manager::existsBelongsTo() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::existsBelongsTo() [2] [FAILED]', PHP_EOL;
}

$success = $manager->existsHasMany('Robots', 'RobotsParts');
if($success==true){
	echo 'Phalcon_Model_Manager::hasMany() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::hasMany() [1] [FAILED]', PHP_EOL;
}

$success = $manager->existsHasMany('Parts', 'RobotsParts');
if($success==true){
	echo 'Phalcon_Model_Manager::hasMany() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::hasMany() [2] [FAILED]', PHP_EOL;
}

$robot = Robots::findFirst();
if($robot!==false){
	echo 'Phalcon_Model_Base::findFirst() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [1] [FAILED]', PHP_EOL;
}

$robotsParts = $robot->getRobotsParts();
if(get_class($robotsParts)=='Phalcon_Model_Resultset'){
	echo 'Phalcon_Model_Manager::getHasManyRecords() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getHasManyRecords() [1] [FAILED]', PHP_EOL;
}

if(count($robotsParts)==3){
	echo 'Phalcon_Model_Manager::getHasManyRecords() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getHasManyRecords() [2] [FAILED]', PHP_EOL;
}

$number = $robot->countRobotsParts();
if($number==3){
	echo 'Phalcon_Model_Manager::getHasManyRecords() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getHasManyRecords() [3] [FAILED]', PHP_EOL;
}

$part = Parts::findFirst();
if($part!==false){
	echo 'Phalcon_Model_Base::findFirst() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [2] [FAILED]', PHP_EOL;
}

$robotsParts = $part->getRobotsParts();
if(get_class($robotsParts)=='Phalcon_Model_Resultset'){
	echo 'Phalcon_Model_Manager::getHasManyRecords() [4] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getHasManyRecords() [4] [FAILED]', PHP_EOL;
}

if(count($robotsParts)==1){
	echo 'Phalcon_Model_Manager::getHasManyRecords() [5] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getHasManyRecords() [5] [FAILED]', PHP_EOL;
}

$number = $part->countRobotsParts();
if($number==1){
	echo 'Phalcon_Model_Manager::getHasManyRecords() [6] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getHasManyRecords() [6] [FAILED]', PHP_EOL;
}

$robotPart = RobotsParts::findFirst();
if($robotPart!==false){
	echo 'Phalcon_Model_Base::findFirst() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [3] [FAILED]', PHP_EOL;
}

$robot = $robotPart->getRobots();
if(get_class($robot)=='Robots'){
	echo 'Phalcon_Model_Manager::getBelongsToRecords() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getBelongsToRecords() [1] [FAILED]', PHP_EOL;
}

$part = $robotPart->getParts();
if(get_class($part)=='Parts'){
	echo 'Phalcon_Model_Manager::getBelongsToRecords() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getBelongsToRecords() [2] [FAILED]', PHP_EOL;
}

$part = $robotPart->getParts();
if(get_class($part)=='Parts'){
	echo 'Phalcon_Model_Manager::getBelongsToRecords() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getBelongsToRecords() [2] [FAILED]', PHP_EOL;
}