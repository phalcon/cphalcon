--TEST--
Phalcon\Debug - Notice: Array to string conversion in Unknown on line 0 - https://github.com/phalcon/cphalcon/issues/1683
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
error_reporting(E_ALL);

$debug = new \Phalcon\Debug();
$debug->listen();

throw new \Exception();
?>
--EXPECTREGEX--
^<html><head>.*$
