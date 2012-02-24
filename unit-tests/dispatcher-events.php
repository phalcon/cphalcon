<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

error_reporting(E_ALL | E_NOTICE | E_STRICT);

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

$dispatcher = new Phalcon_Dispatcher();

$request = Phalcon_Request::getInstance();
$response = Phalcon_Response::getInstance();

$basePath = './';
$dispatcher->setBasePath($basePath);
if($dispatcher->getBasePath()==$basePath){
	echo 'Phalcon_Dispatcher::setBasePath() [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Dispatcher::setBasePath() [FAILED]', PHP_EOL;
	return;
}

$controllersDir = 'tests/controllers/';
$dispatcher->setControllersDir($controllersDir);
if($dispatcher->getControllersDir()==$controllersDir){
	echo 'Phalcon_Dispatcher::setControllersDir() [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Dispatcher::setControllersDir() [FAILED]', PHP_EOL;
	return;
}

$dispatcher->setControllerName('index');
$dispatcher->setActionName('index');
$dispatcher->setParams(array());

try {
	$dispatcher->dispatch($request, $response);
}
catch(Phalcon_Exception $e){
	if($e->getMessage()=="File for controller class IndexController doesn't exists"){
		echo 'Phalcon_Dispatcher::dispatch() [1] [OK]', PHP_EOL;
	} else {
		echo 'Phalcon_Dispatcher::dispatch() [1] [FAILED]', PHP_EOL;
		return;
	}
}

$dispatcher->setControllerName('test5');
$dispatcher->setActionName('notexists');
$dispatcher->setParams(array());
$dispatcher->dispatch($request, $response);
$value = $dispatcher->getActionName();
if($value=='notexists'){
	echo 'Phalcon_Dispatcher::getActionName() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Dispatcher::getActionName() [1] [FAILED]', PHP_EOL;
	return;
}

$value = $dispatcher->getReturnedValue();
if($value=='not-found'){
	echo 'Phalcon_Dispatcher::getReturnedValue() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Dispatcher::getReturnedValue() [1] [FAILED]', PHP_EOL;
	return;
}

$dispatcher->setControllerName('test6');
$dispatcher->setActionName('index');
$dispatcher->setParams(array());
$dispatcher->dispatch($request, $response);
$value = $dispatcher->getReturnedValue();
if($value==false){
	echo 'Phalcon_Dispatcher::beforeDispatch() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Dispatcher::beforeDispatch() [1] [FAILED]', PHP_EOL;
	return;
}