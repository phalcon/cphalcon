--TEST--
Segfault in 1.2.4 - https://github.com/phalcon/cphalcon/issues/1364
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$v = new \Phalcon\Validation();
$v->add("test", new \Phalcon\Validation\Validator\PresenceOf());
$v->validate(array("test"));
?>
--EXPECT--
