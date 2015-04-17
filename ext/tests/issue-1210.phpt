--TEST--
Crash while rendering element's label - https://github.com/phalcon/cphalcon/issues/1210
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$e = new \Phalcon\Forms\Element\Text('test');
$e->setLabel('Test');
echo $e->label(), PHP_EOL;
?>
--EXPECT--
<label for="test">Test</label>
