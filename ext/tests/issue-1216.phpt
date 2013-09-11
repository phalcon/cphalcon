--TEST--
XSS - https://github.com/phalcon/cphalcon/issues/1216
--SKIPIF--
<?php if (!extension_loaded("phalcon")) print "skip"; ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$e  = new \Phalcon\Forms\Element\Text('TEXT');
echo $e->label(array('id' => 'test<', 'class' => 'test>')), PHP_EOL;
echo \Phalcon\Tag::linkTo(array('url"', '<>', 'class' => 'class"')), PHP_EOL;
echo \Phalcon\Tag::textField(array('name"')), PHP_EOL;
echo \Phalcon\Tag::checkField(array('name"')), PHP_EOL;
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
<input type="text" name="name&quot;" id="name&quot;" value="" />
<input type="checkbox" name="name&quot;" id="name&quot;" value="" />
<form method="&gt;" action="/tests/&lt;">
<textarea cols="&lt;" name="&lt;" id="&lt;"></textarea>
<link rel="stylesheet" href="&lt;" type="&gt;" />

<script src="&lt;" type="&gt;"></script>

<img src="&lt;" alt="&gt;" />
<br class="&lt;" />
<select name="&lt;" id="">
	<option value="&quot;">"</option>
	<option selected="selected" value="&gt;">test</option>
</select>
DONE
