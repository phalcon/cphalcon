--TEST--
Assertion failure on unclean shutdown - https://github.com/phalcon/cphalcon/issues/1509
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI();
$di->set('url', function() { return new NonExistingClass; });
$di->get('url');
?>
--EXPECTF--
Fatal error: Class 'NonExistingClass' not found in %s on line %d
