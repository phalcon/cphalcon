--TEST--
Missing argument 1 for MyEntity::readAttribute() - https://github.com/phalcon/cphalcon/issues/1399
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class MyEntity
{
	public function readAttribute($attr)
	{
		return "aaa";
	}
}

$validation = new \Phalcon\Validation();
$validation->add('email', new \Phalcon\Validation\Validator\Email());
$validation->bind(new MyEntity(), array());
$validation->validate();
?>
--EXPECT--
