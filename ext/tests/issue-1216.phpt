--TEST--
XSS - https://github.com/phalcon/cphalcon/issues/1216
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$e  = new \Phalcon\Forms\Element\Text('TEXT');
echo \Phalcon\Tag::linkTo(array('url"', '<>', 'class' => 'class"')), PHP_EOL;
echo \Phalcon\Tag::textField(array('name"', 'class' => 'class"')), PHP_EOL;
echo \Phalcon\Tag::checkField(array('name"', 'class' => 'class"')), PHP_EOL;
echo \Phalcon\Tag::form(array('<', 'method' => '>')), PHP_EOL;
echo \Phalcon\Tag::textArea(array('<', 'cols' => '<')), PHP_EOL;
echo \Phalcon\Tag::stylesheetLink(array('href' => '<', 'local' => false, 'type' => '>')), PHP_EOL;
echo \Phalcon\Tag::javascriptInclude(array('src' => '<', 'local' => false, 'type' => '>')), PHP_EOL;
echo \Phalcon\Tag::image(array('src' => '<', 'alt' => '>'), false), PHP_EOL;
echo \Phalcon\Tag::tagHtml('br', array('class' => '<'), true, false, false), PHP_EOL;
echo \Phalcon\Tag\Select::selectField(array('name' => '<', 'value' => '>', 'id' => ''), array('"' => '"', '>' => 'test')), PHP_EOL;
echo "DONE", PHP_EOL;
?>
--EXPECT--
<a class="class&#x22;" href="/tests/url&#x22;"><></a>
<input class="class&#x22;" name="name&#x22;" id="name&#x22;" value="" type="text" />
<input class="class&#x22;" name="name&#x22;" id="name&#x22;" value="" type="checkbox" />
<form method="&#x3e;" action="/tests/&#x3c;">
<textarea cols="&#x3c;" name="&#x3c;" id="&#x3c;"></textarea>
<link rel="stylesheet" href="&#x3c;" type="&#x3e;" />

<script src="&#x3c;" type="&#x3e;"></script>

<img src="&#x3c;" alt="&#x3e;" />
<br class="&#x3c;" />
<select name="&lt;" id="">
	<option value="&quot;">"</option>
	<option selected="selected" value="&gt;">test</option>
</select>
DONE
