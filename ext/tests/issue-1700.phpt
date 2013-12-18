--TEST--
Memory leak in zim_Phalcon_Tag__inputField() - https://github.com/phalcon/cphalcon/pull/1700
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\Di\FactoryDefault();
Phalcon\Tag::setAutoescape(true);
echo Phalcon\Tag::submitButton('ľščťžýáíéôňď'), PHP_EOL;
?>
--EXPECT--
<input type="submit" value="ľščťžýáíéôňď" />
