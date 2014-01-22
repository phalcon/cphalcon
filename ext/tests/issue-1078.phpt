--TEST--
Support default parameters in Router/URL generation - https://github.com/phalcon/cphalcon/issues/1078
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();

$defController = 'home';
$defAction     = 'index';

$router = $di['router'];
$router->removeExtraSlashes(true)
	->setDefaultNamespace('My\Controllers')
	->setDefaultModule('public')
	->setDefaultController($defController)
	->setDefaultAction($defAction);

$router->add('/:controller/:action/:params', array(
	'controller' => 1,
	'action' => 2,
	'params' => 3
))->setName('secured');

$offset = '/offset/';

$testData = array(
	'secured' => array(
		array('params' => null),
		array('params' => array()),
		array('params' => array('params' => array('a', 1, 'b', 'c'))),
		array('params' => array('params' => array())),
	),
);

foreach ($testData as $routeName => $cases) {
	foreach ($cases as $idx => $case) {
		$url = $di['url'];
		$url->setBaseUri($offset);
		$params = (array)$case['params'] + array('for' => $routeName);
		echo $url->get($params), PHP_EOL;
	}
}
?>
--EXPECT--
/offset/
/offset/
/offset/home/index/a/1/b/c
/offset/home/index/
