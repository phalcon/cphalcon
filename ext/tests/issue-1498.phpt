--TEST--
Log Formatter getTypeString EMERGENCY bug - https://github.com/phalcon/cphalcon/pull/1498
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$logger = new \Phalcon\Logger\Adapter\Stream("php://stdout");
$logger->emergence("This is an emergency");
?>
--EXPECTF--
[%s, %d %s %d %d:%d:%d %s][EMERGENCY] This is an emergency
