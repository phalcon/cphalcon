--TEST--
Missing arguments 1, 2 for closure in beforeMatch - https://github.com/phalcon/cphalcon/issues/1556
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

$router = new \Phalcon\Mvc\Router(false);

$router->add('/test')->beforeMatch(
	function($uri, $route, $router)
	{
		echo $uri, PHP_EOL;
		echo get_class($route), PHP_EOL;
		echo get_class($router), PHP_EOL;
		return true;
	}
);

$router->handle('/test');
?>
--EXPECT--
/test
Phalcon\Mvc\Router\Route
Phalcon\Mvc\Router
