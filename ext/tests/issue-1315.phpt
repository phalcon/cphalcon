--TEST--
\Phalcon\Config descendants throw E_NOTICE on access to a non existent element - https://github.com/phalcon/cphalcon/issues/1315
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
class C extends \Phalcon\Config {}

$c1 = new \Phalcon\Config();
$c2 = new C();

// Internal class, __isset/__get
var_dump(isset($c1->non->existing->value));
var_dump(empty($c1->non->existing->value));

// Internal class, offsetExists/offsetGet
var_dump(isset($c1['non']['existing']['value']));
var_dump(empty($c1['non']['existing']['value']));

// Userspace class, __isset/__get
var_dump(isset($c2->non->existing->value));
var_dump(empty($c2->non->existing->value));

// Userspace class, offsetExists/offsetGet
var_dump(isset($c2['non']['existing']['value']));
var_dump(empty($c2['non']['existing']['value']));
?>
--EXPECT--
bool(false)
bool(true)
bool(false)
bool(true)
bool(false)
bool(true)
bool(false)
bool(true)
