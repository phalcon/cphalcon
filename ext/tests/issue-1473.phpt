--TEST--
Faster version of Phalcon\DI using object handlers - https://github.com/phalcon/cphalcon/pull/1473
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class MyDI extends \Phalcon\DI
{
	public function offsetGet($offset)
	{
		echo __METHOD__, PHP_EOL;
		return parent::offsetGet($offset);
	}

	public function offsetSet($offset, $value)
	{
		echo __METHOD__, PHP_EOL;
		return parent::offsetSet($offset, $value);
	}

	public function offsetExists($offset)
	{
		echo __METHOD__, PHP_EOL;
		return parent::offsetExists($offset);
	}

	public function offsetUnset($offset)
	{
		echo __METHOD__, PHP_EOL;
		return parent::offsetUnset($offset);
	}

	public function __call($method, $params = null)
	{
		echo __METHOD__, PHP_EOL;
		if ('test' == $method) {
			$method = 'getTest';
		}

		return parent::__call($method, $params);
	}

	public function __clone()
	{
		echo __METHOD__, PHP_EOL;
		return parent::__clone();
	}
}

$di = new MyDI();
$di['test'] = function() { return new stdClass(); };
$di['test'];
var_dump(isset($di['test']));
var_dump(get_class($di->test()));

try {
	$s = serialize($di);
}
catch (Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}

$s = 'C:20:"Phalcon\\DI":0:{}';
$x = unserialize($s);

$s = 'O:20:"Phalcon\\DI":0:{}';
$x = unserialize($s);

$clone = clone $di;
var_dump(isset($clone['test']));
var_dump(get_class($clone->test()));

try {
	$di->somethingWeird();
}
catch (\Phalcon\DI\Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}

unset($clone['test']);
var_dump(isset($di['test']));
?>
--EXPECTF--
MyDI::offsetSet
MyDI::offsetGet
MyDI::offsetExists
bool(true)
MyDI::__call
string(8) "stdClass"
Serialization of 'MyDI' is not allowed

Notice: unserialize(): Error at offset %d of %d bytes in %s on line %d

Notice: unserialize(): Error at offset %d of %d bytes in %s on line %d
MyDI::__clone
MyDI::offsetExists
bool(true)
MyDI::__call
string(8) "stdClass"
MyDI::__call
Call to undefined method or service 'somethingWeird'
MyDI::offsetUnset
MyDI::offsetExists
bool(true)
