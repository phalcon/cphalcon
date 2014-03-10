--TEST--
Custom validator = signal aborted - https://github.com/phalcon/cphalcon/issues/2096
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
class MyValidation extends \Phalcon\Validation
{
}

$v = new \MyValidation();
$v->add('username', new \Phalcon\Validation\Validator\PresenceOf());
$v->validate(array());
?>
--EXPECT--
