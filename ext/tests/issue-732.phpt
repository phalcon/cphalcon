--TEST--
Phalcon\Config::offsetUnset() does not work - https://github.com/phalcon/cphalcon/issues/732
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$a = new Phalcon\Config(array('a' => 0));
assert(isset($a['a']));
unset($a['a']);
assert(!isset($a['a']));
?>
--EXPECT--
