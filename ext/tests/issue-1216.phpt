--TEST--
XSS - https://github.com/phalcon/cphalcon/issues/1216
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$e  = new \Phalcon\Forms\Element\Text('TEXT');
echo $e->label(array('id' => 'test<', 'class' => 'test>')), PHP_EOL;
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
<label for="test&lt;" id="test&lt;" class="test&gt;">test<</label>
<a href="/tests/url&quot;" class="class&quot;"><></a>
<input type="text" id="name&quot;" name="name&quot;" class="class&quot;" />
<input type="checkbox" id="name&quot;" name="name&quot;" class="class&quot;" />
<form action="/tests/&lt;" method="&gt;">
<textarea id="&lt;" name="&lt;" cols="&lt;"></textarea>
<link rel="stylesheet" type="&gt;" href="&lt;" />

<script type="&gt;" src="&lt;"></script>

<img src="&lt;" alt="&gt;" />
<br class="&lt;" />
<select id="" name="&lt;">
	<option value="&quot;">"</option>
	<option selected="selected" value="&gt;">test</option>
</select>
DONE
