--TEST--
Inconsistent behavior of Phalcon\Tag::setAutoescape() - https://github.com/phalcon/cphalcon/issues/1263
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
new \Phalcon\DI\FactoryDefault();

var_dump(\Phalcon\Tag::getAutoescape());

\Phalcon\Tag::setAutoescape(false);
var_dump(\Phalcon\Tag::getAutoescape());
echo \Phalcon\Tag::textField(array('name', 'value' => '&"')), PHP_EOL;

\Phalcon\Tag::setAutoescape(true);
var_dump(\Phalcon\Tag::getAutoescape());
echo \Phalcon\Tag::textField(array('name', 'value' => '&"')), PHP_EOL;

\Phalcon\Tag::setAutoescape(false);
\Phalcon\Tag::setDefault('name', '&"');
echo \Phalcon\Tag::textField(array('name')), PHP_EOL;

\Phalcon\Tag::setAutoescape(true);
\Phalcon\Tag::setDefault('name', '&"');
echo \Phalcon\Tag::textField(array('name')), PHP_EOL;
?>
--EXPECT--
bool(true)
bool(false)
<input value="&"" name="name" id="name" type="text" />
bool(true)
<input value="&#x26;&#x22;" name="name" id="name" type="text" />
<input name="name" id="name" value="&"" type="text" />
<input name="name" id="name" value="&#x26;&#x22;" type="text" />

