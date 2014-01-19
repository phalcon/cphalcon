--TEST--
Router incorrectly handles numeric controllers/actions - https://github.com/phalcon/cphalcon/issues/1688
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class ControllerController
{
	public function indexAction()
	{
	}

	public function editAction()
	{
	}
}

$di = new \Phalcon\DI\FactoryDefault();

$router = new \Phalcon\Mvc\Router(false);
$router->add(
	'/admin/:controller',
	array(
		'module'     => 'test',
		'controller' => 1,
		'action'     => 'index',
	)
);

$router->add(
	'/admin/:controller/:action',
	array(
		'module'     => 'test',
		'controller' => 1,
		'action'     => 2,
	)
);

$tests = array(
	'/admin/controller',
	'/admin/123',
	'/admin/controller/edit',
	'/admin/controller/123',
);

$em = new \Phalcon\Events\Manager();
$em->attach(
	"dispatch:beforeException",
	function($event, $dispatcher, $exception)
	{
		if ($exception instanceof \Phalcon\Mvc\Dispatcher\Exception) {
			$dispatcher->setActionName('notFound');
			return false;
		}
	}
);

foreach ($tests as $path) {
	$router->handle($path);
	var_dump($router->wasMatched());
	var_dump('Router: Controller: ' . $router->getControllerName());
	var_dump('Router: Action: ' . $router->getActionName());

	$dispatcher = new \Phalcon\Mvc\Dispatcher();
	$dispatcher->setDI($di);
	$dispatcher->setEventsManager($em);
	$dispatcher->setControllerName($router->getControllerName());
	$dispatcher->setActionName($router->getActionName());
	$dispatcher->setParams($router->getParams());
	try {
		$dispatcher->dispatch();
	}
	catch (\Exception $e) {
		echo $e->getMessage(), PHP_EOL;
	}

	var_dump('Dispatcher: Controller: ' . $dispatcher->getControllerName());
	var_dump('Dispatcher: Action: ' . $dispatcher->getActionName());
}
?>
--EXPECT--
bool(true)
string(30) "Router: Controller: controller"
string(21) "Router: Action: index"
string(34) "Dispatcher: Controller: controller"
string(25) "Dispatcher: Action: index"
bool(true)
string(23) "Router: Controller: 123"
string(21) "Router: Action: index"
string(27) "Dispatcher: Controller: 123"
string(28) "Dispatcher: Action: notFound"
bool(true)
string(30) "Router: Controller: controller"
string(20) "Router: Action: edit"
string(34) "Dispatcher: Controller: controller"
string(24) "Dispatcher: Action: edit"
bool(true)
string(30) "Router: Controller: controller"
string(19) "Router: Action: 123"
string(34) "Dispatcher: Controller: controller"
string(28) "Dispatcher: Action: notFound"
