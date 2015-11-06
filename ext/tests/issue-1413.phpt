--TEST--
Phalcon\Forms\Element::toString() throws exceptions - https://github.com/phalcon/cphalcon/issues/1413
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$e = new \Phalcon\Forms\Element\Text('name', array('value' => '&&&'));
echo $e, PHP_EOL;
?>
--EXPECTF--
<input type="text" id="name" name="name" value="&amp;&amp;&amp;" />
