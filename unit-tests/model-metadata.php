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

$connection = $Personas->getConnection();
if($connection==Phalcon_Db_Pool::getConnection()){
	echo 'Personas::getConnection() vs. Phalcon_Db_Pool::getConnection() [1] [OK]', PHP_EOL;
} else {
	echo 'Personas::getConnection() vs. Phalcon_Db_Pool::getConnection() [1] [FAILED]', PHP_EOL;
}

$metaData = new Phalcon_Model_MetaData('Memory');

$pAttributes = array(
	0 => 'cedula',
	1 => 'tipo_documento_id',
	2 => 'nombres',
	3 => 'telefono',
	4 => 'direccion',
	5 => 'email',
	6 => 'fecha_nacimiento',
	7 => 'ciudad_id',
	8 => 'creado_at',
	9 => 'cupo',
	10 => 'estado',
);

$attributes = $metaData->getAttributes($Personas);
if($attributes==$pAttributes){
	echo 'Phalcon_Model_MetaData::getAttributes() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_MetaData::getAttributes() [1] [FAILED]', PHP_EOL;
}

$ppkAttributes = array(
	0 => 'cedula'
);

$pkAttributes = $metaData->getPrimaryKeyAttributes($Personas);
if($ppkAttributes==$pkAttributes){
	echo 'Phalcon_Model_MetaData::getPrimaryKeyAttributes() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_MetaData::getPrimaryKeyAttributes() [1] [FAILED]', PHP_EOL;
}

$pnpkAttributes = array(
	0 => 'tipo_documento_id',
	1 => 'nombres',
	2 => 'telefono',
	3 => 'direccion',
	4 => 'email',
	5 => 'fecha_nacimiento',
	6 => 'ciudad_id',
	7 => 'creado_at',
	8 => 'cupo',
	9 => 'estado',
);

$npkAttributes = $metaData->getNonPrimaryKeyAttributes($Personas);
if($pnpkAttributes==$npkAttributes){
	echo 'Phalcon_Model_MetaData::getNonPrimaryKeyAttributes() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_MetaData::getNonPrimaryKeyAttributes() [1] [FAILED]', PHP_EOL;
}

$pnnAttributes = array(
	0 => 'cedula',
	1 => 'tipo_documento_id',
	2 => 'nombres',
	3 => 'cupo',
	4 => 'estado'
);

$nnAttributes = $metaData->getNotNullAttributes($Personas);
if($nnAttributes==$pnnAttributes){
	echo 'Phalcon_Model_MetaData::getNotNullAttributes() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_MetaData::getNotNullAttributes() [1] [FAILED]', PHP_EOL;
}

$pdtAttributes = array(
  'cedula' => 'char(15)',
  'tipo_documento_id' => 'int(3) unsigned',
  'nombres' => 'varchar(100)',
  'telefono' => 'varchar(20)',
  'direccion' => 'varchar(100)',
  'email' => 'varchar(50)',
  'fecha_nacimiento' => 'date',
  'ciudad_id' => 'int(10) unsigned',
  'creado_at' => 'date',
  'cupo' => 'decimal(16,2)',
  'estado' => 'enum(\'A\',\'I\')',
);

$dtAttributes = $metaData->getDataTypes($Personas);
if($dtAttributes==$pdtAttributes){
	echo 'Phalcon_Model_MetaData::getDataTypes() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_MetaData::getDataTypes() [1] [FAILED]', PHP_EOL;
}

$pndAttributes = array(
	'tipo_documento_id' => true,
	'ciudad_id' => true,
	'cupo' => true,
);
$ndAttributes = $metaData->getDataTypesNumeric($Personas);
if($ndAttributes==$pndAttributes){
	echo 'Phalcon_Model_MetaData::getDataTypesNumeric() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Model_MetaData::getDataTypesNumeric() [1] [FAILED]', PHP_EOL;
}
