--TEST--
Allow to set dirs without trailing slashes - https://github.com/phalcon/cphalcon/issues/406
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$view = new \Phalcon\Mvc\View();
$funcs = array('PartialsDir', 'LayoutsDir', 'ViewsDir');
foreach ($funcs as $func) {
	$getter = 'get' . $func;
	$setter = 'set' . $func;

	$view->$setter('');
	echo str_replace(DIRECTORY_SEPARATOR, '/', $view->$getter()), PHP_EOL;

	$view->$setter('test');
	echo str_replace(DIRECTORY_SEPARATOR, '/', $view->$getter()), PHP_EOL;

	$view->$setter('test/');
	echo str_replace(DIRECTORY_SEPARATOR, '/', $view->$getter()), PHP_EOL;
}

echo "DONE", PHP_EOL;
?>
--EXPECT--

test/
test/

test/
test/

test/
test/
DONE
