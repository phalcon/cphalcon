--TEST--
isset/empty return wrong value on inherited config class and fluent interface - https://github.com/phalcon/cphalcon/issues/1362
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
class C extends \Phalcon\Config
{
}

$c1 = new \Phalcon\Config(array("a" => array("b" => 1)));
$c2 = new               C(array("a" => array("b" => 1)));

var_dump(isset($c1->a->b));
var_dump(isset($c2->a->b));
var_dump(isset($c1['a']['b']));
var_dump(isset($c2['a']['b']));
?>
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(true)
