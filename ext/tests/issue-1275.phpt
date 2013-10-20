--TEST--
No action or controller set for view in v1.2.4 - https://github.com/phalcon/cphalcon/issues/1275
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
/**
 * @RoutePrefix("/hello")
 */
class HelloController extends \Phalcon\Mvc\Controller
{
	/**
	 * @Get("/test")
	 */
	public function testAction()
	{
		echo $this->dispatcher->getControllerName(), PHP_EOL;
	}
}

$di = new \Phalcon\DI\FactoryDefault();
$di->setShared('view', function() { return new \Phalcon\Mvc\View(); });
$di->setShared('router',
	function()
	{
		$router = new \Phalcon\Mvc\Router\Annotations(false);
		$router->setUriSource(Phalcon\Mvc\Router::URI_SOURCE_SERVER_REQUEST_URI);
		$router->addResource('Hello');
		return $router;
	}
);

$application = new \Phalcon\Mvc\Application($di);

$_SERVER['REQUEST_METHOD'] = 'GET';
$_SERVER['REQUEST_URI'] = '/hello/test';
echo $application->handle()->getContent();
?>
--EXPECT--
Hello
