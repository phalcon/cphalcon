<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

$config = new Phalcon_Config(array(
	'database' => array(
		'adapter' => 'Mysql',
		'host' => '192.168.0.28',
		'username' => 'support',
		'password' => 'H45pov682v',
		'name' => 'demo'
	),
	'phalcon' => array(
		'controllersDir' => 'tests/controllers/',
		'modelsDir' => 'tests/models/phalcon/',
		'viewsDir' => 'tests/views/',
		'basePath' => './'
	)
));


$front = Phalcon_Controller_Front::getInstance();

echo $front->getBaseUri();

$_GET['_url'] = 'test3/other';
$front->setConfig($config);
$view = $front->dispatchLoop();

if($view->getContent()=='lolhere'){
	echo 'Phalcon_Controller_Front::dispatchLoop() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Controller_Front::dispatchLoop() [1] [FAILED]', PHP_EOL;
	return;
}
