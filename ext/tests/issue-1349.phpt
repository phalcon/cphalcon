--TEST--
Phalcon\Forms\Form::getMessages() produces PHP error if form is valid - https://github.com/phalcon/cphalcon/issues/1349
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$form = new \Phalcon\Forms\Form;
$form->add(new \Phalcon\Forms\Element\Text('name'));
$form->isValid(array('name' => 'John'));
assert(get_class($form->getMessages(false)) == 'Phalcon\Validation\Message\Group');
?>
--EXPECT--
