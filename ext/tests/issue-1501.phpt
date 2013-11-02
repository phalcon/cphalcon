--TEST--
Segmentation Fault on var_dump() - https://github.com/phalcon/cphalcon/issues/1501
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di     = new \Phalcon\DI\FactoryDefault();
$url    = $di->get('url');
$router = $di->get('router');
ob_start();
var_dump($di);
ob_end_clean();
?>
--EXPECT--
