--TEST--
\Phalcon\Tag::form - [cosmetic] extra spaces - https://github.com/phalcon/cphalcon/issues/57
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
new \Phalcon\DI\FactoryDefault;
echo \Phalcon\Tag::form('about/index'), PHP_EOL;
echo \Phalcon\Tag::form(array('about/list', 'method' => 'get')), PHP_EOL;
echo \Phalcon\Tag::endForm(), PHP_EOL;
?>
--EXPECT--
<form method="post" action="/tests/about/index">
<form method="get" action="/tests/about/list">
</form>
