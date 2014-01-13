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
<input value="&#x13e;&#x161;&#x10d;&#x165;&#x17e;&#xfd;&#xe1;&#xed;&#xe9;&#xf4;&#x148;&#x10f;" type="submit" />
