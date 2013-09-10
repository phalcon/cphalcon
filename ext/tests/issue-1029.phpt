--TEST--
Phalcon\Forms\Form::label() extra param - https://github.com/phalcon/cphalcon/issues/1029
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$form = new \Phalcon\Forms\Form();
$form->add(new \Phalcon\Forms\Element\Text("name"));
$telephone = new \Phalcon\Forms\Element\Text("telephone");
$telephone->setLabel("The Telephone");
$form->add($telephone);
echo $form->label('name', array('class' => 'form-control')), PHP_EOL;
echo $form->label('telephone', array('class' => 'form-control')), PHP_EOL;
?>
--EXPECT--
<label for="name" class="form-control">name</label>
<label for="telephone" class="form-control">The Telephone</label>
