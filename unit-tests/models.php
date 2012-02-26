<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

$config = array(
	'adapter' => 'Mysql',
	'host' => '192.168.0.20',
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

$Personas = $modelManager->getModel('Personas');
if(get_class($Personas)=='Personas'){
	echo 'Phalcon_Model_Manager::getModel() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getModel() [1] [FAILED]', PHP_EOL;
	return false;
}

$People = $modelManager->getModel('People');
if(get_class($People)=='People'){
	echo 'Phalcon_Model_Manager::getModel() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getModel() [2] [FAILED]', PHP_EOL;
	return false;
}

$manager = People::getManager();
if(get_class($manager)=='Phalcon_Model_Manager'){
	echo 'Phalcon_Model_Manager::getManager() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Manager::getManager() [1] [FAILED]', PHP_EOL;
	return false;
}

//Count tests
if(People::count()==Personas::count()){
	echo 'Phalcon_Model_Base::count() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::count() [1] [FAILED]', PHP_EOL;
	return false;
}

$params = array();
if(People::count($params)==Personas::count($params)){
	echo 'Phalcon_Model_Base::count() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::count() [2] [FAILED]', PHP_EOL;
	return false;
}

$params = array("estado='I'");
if(People::count($params)==Personas::count($params)){
	echo 'Phalcon_Model_Base::count() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::count() [3] [FAILED]', PHP_EOL;
	return false;
}

$params = "estado='I'";
if(People::count($params)==Personas::count($params)){
	echo 'Phalcon_Model_Base::count() [4] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::count() [4] [FAILED]', PHP_EOL;
	return false;
}

$params = array("conditions" => "estado='I'");
if(People::count($params)==Personas::count($params)){
	echo 'Phalcon_Model_Base::count() [5] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::count() [5] [FAILED]', PHP_EOL;
	return false;
}

//Count tests
$people = People::findFirst();
if(is_object($people)){
	echo 'Phalcon_Model_Base::findFirst() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [1] [FAILED]', PHP_EOL;
	return false;
}

if(get_class($people)=='People'){
	echo 'Phalcon_Model_Base::findFirst() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [2] [FAILED]', PHP_EOL;
	return false;
}

$persona = Personas::findFirst();
if($people->nombres==$persona->nombres){
	echo 'Phalcon_Model_Base::findFirst() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [3] [FAILED]', PHP_EOL;
	return false;
}

if($people->estado==$persona->estado){
	echo 'Phalcon_Model_Base::findFirst() [4] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [4] [FAILED]', PHP_EOL;
	return false;
}

$people = People::findFirst("estado='I'");
$persona = Personas::findFirst("estado='I'");
if($people->nombres==$persona->nombres){
	echo 'Phalcon_Model_Base::findFirst() [5] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [5] [FAILED]', PHP_EOL;
	return false;
}

$people = People::findFirst(array("estado='I'"));
$persona = Personas::findFirst(array("estado='I'"));
if($people->nombres==$persona->nombres){
	echo 'Phalcon_Model_Base::findFirst() [6] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [6] [FAILED]', PHP_EOL;
	return false;
}

$params = array("conditions" => "estado='I'");
$people = People::findFirst($params);
$persona = Personas::findFirst($params);
if($people->nombres==$persona->nombres){
	echo 'Phalcon_Model_Base::findFirst() [7] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [7] [FAILED]', PHP_EOL;
	return false;
}

$params = array("conditions" => "estado='A'", "order" => "nombres");
$people = People::findFirst($params);
$persona = Personas::findFirst($params);
if($people->nombres==$persona->nombres){
	echo 'Phalcon_Model_Base::findFirst() [8] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [8] [FAILED]', PHP_EOL;
	return false;
}

$params = array("estado='A'", "order" => "nombres DESC", "limit" => 30);
$people = People::findFirst($params);
$persona = Personas::findFirst($params);
if($people->nombres==$persona->nombres){
	echo 'Phalcon_Model_Base::findFirst() [9] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [9] [FAILED]', PHP_EOL;
	return false;
}

$personas = Personas::find();
$people = People::find();
if(count($personas)==count($people)){
	echo 'Phalcon_Model_Base::find() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::find() [1] [FAILED]', PHP_EOL;
	return false;
}

$personas = Personas::find("estado='I'");
$people = People::find("estado='I'");
if(count($personas)==count($people)){
	echo 'Phalcon_Model_Base::find() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::find() [2] [FAILED]', PHP_EOL;
	return false;
}

$personas = Personas::find(array("estado='I'"));
$people = People::find(array("estado='I'"));
if(count($personas)==count($people)){
	echo 'Phalcon_Model_Base::find() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::find() [3] [FAILED]', PHP_EOL;
	return false;
}

$personas = Personas::find(array("estado='A'", "order" => "nombres"));
$people = People::find(array("estado='A'", "order" => "nombres"));
if(count($personas)==count($people)){
	echo 'Phalcon_Model_Base::find() [4] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::find() [4] [FAILED]', PHP_EOL;
	return false;
}

$personas = Personas::find(array("estado='A'", "order" => "nombres", "limit" => 100));
$people = People::find(array("estado='A'", "order" => "nombres", "limit" => 100));
if(count($personas)==count($people)){
	echo 'Phalcon_Model_Base::find() [5] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::find() [5] [FAILED]', PHP_EOL;
	return false;
}

$number = 0;
$peoples = Personas::find(array("conditions" => "estado='A'", "order" => "nombres", "limit" => 20));
foreach($peoples as $people){
	$number++;
}
if($number==20){
	echo 'Phalcon_Model_Base::find() [6] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::find() [6] [FAILED]', PHP_EOL;
	return false;
}

$persona = new Personas($modelManager);
$persona->cedula = 'CELL'.mt_rand(0, 9999);
if($persona->save()==false){
	echo 'Phalcon_Model_Base::save() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::save() [1] [FAILED]', PHP_EOL;
	return false;
}

if(count($persona->getMessages())==4){
	echo 'Phalcon_Model_Base::getMessages() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::getMessages() [1] [FAILED]', PHP_EOL;
	return false;
}

$messages = array(
	0 => Phalcon_Model_Message::__set_state(array(
		'_type' => 'PresenceOf',
		'_message' => 'tipo_documento is required',
		'_field' => 'tipo_documento_id',
	)),
	1 => Phalcon_Model_Message::__set_state(array(
		'_type' => 'PresenceOf',
		'_message' => 'nombres is required',
		'_field' => 'nombres',
	)),
	2 => Phalcon_Model_Message::__set_state(array(
		'_type' => 'PresenceOf',
		'_message' => 'cupo is required',
		'_field' => 'cupo',
	)),
	3 => Phalcon_Model_Message::__set_state(array(
		'_type' => 'PresenceOf',
		'_message' => 'estado is required',
		'_field' => 'estado',
	)),
);

if($persona->getMessages()==$messages){
	echo 'Phalcon_Model_Base::getMessages() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::getMessages() [2] [FAILED]', PHP_EOL;
	return false;
}

$persona = new Personas($modelManager);
$persona->cedula = 'CELL'.mt_rand(0, 9999);
$persona->tipo_documento_id = 1;
$persona->nombres = 'LOST';
$persona->telefono = '1';
$persona->cupo = 20000;
$persona->estado = 'A';
if($persona->save()==true){
	echo 'Phalcon_Model_Base::save() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::save() [2] [FAILED]', PHP_EOL;
	return false;
}

$persona = new Personas($modelManager);
$persona->cedula = 'CELL'.mt_rand(0, 9999);
$persona->tipo_documento_id = 1;
$persona->nombres = 'LOST LOST';
$persona->telefono = '2';
$persona->cupo = 0;
$persona->estado = 'X';
if($persona->save()==true){
	echo 'Phalcon_Model_Base::save() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::save() [3] [FAILED]', PHP_EOL;
	return false;
}

$persona = Personas::findFirst(array("estado='X'"));
if($persona!==false){
	echo 'Phalcon_Model_Base::findFirst() [9] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [9] [FAILED]', PHP_EOL;
	return false;
}

if($persona->nombres=='LOST LOST'){
	echo 'Phalcon_Model_Base::findFirst() [10] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [10] [FAILED]', PHP_EOL;
	return false;
}

if($persona->estado=='X'){
	echo 'Phalcon_Model_Base::findFirst() [11] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [11] [FAILED]', PHP_EOL;
	return false;
}

$difEstados = People::count(array("distinct" => "estado"));
if($difEstados==4){
	echo 'Phalcon_Model_Base::count() [6] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::count() [6] [FAILED]', PHP_EOL;
	return false;
}

$group = People::count(array("group" => "estado"));
if(count($group)==4){
	echo 'Phalcon_Model_Base::count() [7] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::count() [7] [FAILED]', PHP_EOL;
	return false;
}


$persona = Personas::findFirst(array("estado='X'"));
if($persona!==false){
	echo 'Phalcon_Model_Base::findFirst() [12] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [12] [FAILED]', PHP_EOL;
	return false;
}

$before = People::count();
if($persona->delete()==true){
	echo 'Phalcon_Model_Base::findFirst() [12] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::findFirst() [12] [FAILED]', PHP_EOL;
	return false;
}

if(($before-1)==People::count()){
	echo 'Phalcon_Model_Base::delete() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_Base::delete() [1] [FAILED]', PHP_EOL;
	return false;
}
