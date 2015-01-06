--TEST--
Segmentation fault in \Phalcon\Mvc\View\Engine\Volt\Compiler::expression() - https://github.com/phalcon/cphalcon/issues/1392
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
error_reporting(error_reporting() & ~E_NOTICE);

$c      = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
$types  = array(311, 124, 33, 42, 43, 45, 47, 37, 60, 61, 62, 126, 278, 266, 267, 270, 271, 272, 273, 274, 275, 276, 356, 361, 365, 362, 363, 309, 369, 366, 367, 368);
$passed = 0;

foreach ($types as $type) {
	try {
		$c->expression(array('type' => $type));
	}
	catch (Exception $e) {
	}

	++$passed;
}

assert($passed == count($types));
?>
--EXPECT--
