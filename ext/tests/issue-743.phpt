--TEST--
Segmentation Fault in Phalcon\Validation::bind() - https://github.com/phalcon/cphalcon/pull/743
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$v = new \Phalcon\Validation;
try {
	$v->bind(0, 0);
}
catch (Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECT--
The entity must be an object
