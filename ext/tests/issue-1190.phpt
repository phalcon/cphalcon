--TEST--
Form.render doesn't escape value attributes on TextFields - https://github.com/phalcon/cphalcon/issues/1190
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
new \Phalcon\DI\FactoryDefault();
$object = new stdClass();
$object->title = 'Hello "world!"';
$form = new \Phalcon\Forms\Form($object);
$form->add(new \Phalcon\Forms\Element\Text("title"));
echo $form->render('title'), PHP_EOL;
?>
--EXPECT--
<input type="text" id="title" name="title" value="Hello &quot;world!&quot;" />
