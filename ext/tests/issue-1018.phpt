--TEST--
Phalcon\Element::addFilter() prepends inserts NULL as the first element - https://github.com/phalcon/cphalcon/issues/1018
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di    = new \Phalcon\DI\FactoryDefault();
$form  = new \Phalcon\Forms\Form();
$email = new \Phalcon\Forms\Element\Text('email');
$email->addValidator(new \Phalcon\Validation\Validator\Email());
$email->addFilter('trim');
$form->add($email);
$data = array('email' => 'example@example.com');
assert($form->isValid($data));
?>
--EXPECT--
