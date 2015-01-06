--TEST--
Do not allow to override superglobals in views - https://github.com/phalcon/cphalcon/pull/1617
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di     = new \Phalcon\DI\FactoryDefault();
$view   = new \Phalcon\Mvc\View();
$engine = new \Phalcon\Mvc\View\Engine\Php($view, $di);

foreach (array('_GET', '_POST', '_COOKIE', 'GLOBALS') as $v) {
	$view->setVar($v, strtolower($v));
}

var_dump($view->getParamsToView());
var_dump($engine->render(__DIR__ . '/views/superglobals.phtml', $view->getParamsToView(), false));
?>
--EXPECT--
array(4) {
  ["_GET"]=>
  string(4) "_get"
  ["_POST"]=>
  string(5) "_post"
  ["_COOKIE"]=>
  string(7) "_cookie"
  ["GLOBALS"]=>
  string(7) "globals"
}
array
array
array
array
bool(true)
