--TEST--
Phalcon\Http\Cookie::__toString() must return a string value - https://github.com/phalcon/cphalcon/issue/1428
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$c = new \Phalcon\Http\Cookie('name');
echo $c, PHP_EOL;
?>
--EXPECT--

