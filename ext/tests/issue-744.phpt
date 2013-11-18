--TEST--
Segmentation Fault in Phalcon\Tag::setDI() and setDefaults() - https://github.com/phalcon/cphalcon/pull/744
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
class DIDescendant extends Phalcon\DI {}

$v = new \Phalcon\Tag();

try {
	$v->setDI(0);
	assert(false);
}
catch (Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}

/* This won't work — we do not validate DI yet :-(
try {
	$v->setDI(new \stdClass());
	assert(false);
}
catch (Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}
*/

$v->setDI(new \Phalcon\DI());
echo "OK", PHP_EOL;

$v->setDI(new \DIDescendant());
echo "OK", PHP_EOL;

try {
	$v->setDefaults(0);
	assert(false);
}
catch (Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECT--
Unexpected value type: expected object implementing Phalcon\DiInterface, integer given
OK
OK
An array is required as default values
