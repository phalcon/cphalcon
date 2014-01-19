--TEST--
$view->addFilter does not work in 1.3.0 - https://github.com/phalcon/cphalcon/issues/1828
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

$view = new \Phalcon\Mvc\View();
$di   = new \Phalcon\DI\FactoryDefault();
$volt = new \Phalcon\Mvc\View\Engine\Volt($view, $di);
$volt->setOptions(array(
	"compiledPath" => '',
	"compiledExtension" => ".compiled",
));

$volt->getCompiler()->addFilter('myfilter', 'md5');
$volt->getCompiler()->addFilter('myfilter', function () {
	return 'somevalue';
});
?>
--EXPECT--
