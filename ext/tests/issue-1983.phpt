--TEST--
Segmentation Fault in Phalcon\DI\Injectable::__get() - https://github.com/phalcon/cphalcon/issues/1983
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class TestClass extends \Phalcon\DI\Injectable
{
	public function test()
	{
		$a = $this->__get(1);
	}
}

new \Phalcon\DI;
$x = new TestClass();
$x->test();
?>
--EXPECTF--
Warning: %s::__get(): Access to undefined property %s::1 in %s on line %d
