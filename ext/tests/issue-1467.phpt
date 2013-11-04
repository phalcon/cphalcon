--TEST--
Phalcon\DI::reset() is buggy - https://github.com/phalcon/cphalcon/issues/1467
--SKIPIF--
<?php include('skipif.inc');
--FILE--
<?php
\Phalcon\Di::reset();
$di = new \Phalcon\DI\FactoryDefault();
?>
--EXPECT--
