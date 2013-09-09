--TEST--
Crash while rendering element's label - https://github.com/phalcon/cphalcon/issues/1210
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip"; ?>
--FILE--
<?php
$e = new \Phalcon\Forms\Element\Text('test');
$e->setLabel('Test');
echo $e->label(), PHP_EOL;
?>
--EXPECTF--
<label for="test">Test</label>
