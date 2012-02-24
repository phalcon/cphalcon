<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

Phalcon_Db_Pool::setDefaultDescriptor(array(
	'adapter' => 'Mysql',
	'host' => '192.168.0.20',
	'username' => 'support',
	'password' => 'H45pov682v',
	'name' => 'demo'
));

$model = new Phalcon_Model_Manager();
$model->setModelsDir('tests/models/phalcon/');

$view = new Phalcon_View();
$view->setViewsDir('tests/views/');

$dispatcher = new Phalcon_Dispatcher();

$request = Phalcon_Request::getInstance();
$response = Phalcon_Response::getInstance();

$dispatcher->setBasePath('./');
$dispatcher->setControllersDir('tests/controllers/');

require 'tests/controllers/Test4Controller.php';

$controller = new Test4Controller($dispatcher, $request, $response, $view, $model);

$_POST['email'] = ';ans@ecom.com';
if($controller->requestAction()=='ans@ecom.com'){
	echo 'Phalcon_Controller::$request [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Controller::$request [1] [FAILED]', PHP_EOL;
	return;
}

$controller->viewAction();
if(count($view->getParamsToView())==1){
	echo 'Phalcon_Controller::$view [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Controller::$view [1] [FAILED]', PHP_EOL;
	return;
}

$records = $controller->modelAction();
if(get_class($records)=='Phalcon_Model_Resultset'){
	echo 'Phalcon_Controller::$model [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Controller::$model [1] [FAILED]', PHP_EOL;
	return;
}	