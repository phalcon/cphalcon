--TEST--
Phalcon\Forms\Element::toString() throws exceptions - https://github.com/phalcon/cphalcon/issues/1413
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$e = new \Phalcon\Forms\Element\Text('name', array('value' => '&&&'));
echo $e, PHP_EOL;
?>
--EXPECTF--
Fatal error: A dependency injector container is required to obtain the "escaper" service in %s on line %d
