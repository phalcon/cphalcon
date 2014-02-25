--TEST--
The argument is not iterable - https://github.com/phalcon/cphalcon/issues/2047
--GET--
dummy=1
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$di['response']->getHeaders()->send();
?>
--EXPECT--
