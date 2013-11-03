--TEST--
Phalcon\Config crashes on recursive arrays - https://github.com/phalcon/cphalcon/issues/1504
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$a = array();
$a['a'] = &$a;
$c = new \Phalcon\Config($a);
?>
--EXPECTF--
Warning: Phalcon\Config::__construct(): Recursion detected in %s on line %d
