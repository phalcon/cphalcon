--TEST--
Misleading diagnostics on exception - https://github.com/phalcon/cphalcon/pull/1297
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
try {
	$object = new stdClass();
	$form = new \Phalcon\Forms\Form($object);
	$form->add(new \Phalcon\Forms\Element\Text("title"));
	echo $form->render('title');
}
catch (\Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}

echo "OK", PHP_EOL;
?>
--EXPECT--
A dependency injector container is required to obtain the "escaper" service
OK
