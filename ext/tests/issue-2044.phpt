--TEST--
Replace varnames of empty language content - https://github.com/phalcon/cphalcon/issues/2044
--SKIPIF--
<?php include('skipif.inc');
--FILE--
<?php
$t = new Phalcon\Translate\Adapter\NativeArray(array('content' => array()));
echo $t->_("Hello %varname%", array('varname' => 'world')), PHP_EOL;
?>
--EXPECT--
Hello world
