--TEST--
Phalcon\Mvc\Model\Validator\Email validates malformed emails as correct - https://github.com/phalcon/cphalcon/issues/1243
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
class FakeModel
{
	public $email = 'username.@domain.com';

	public function readAttribute($field)
	{
		return $this->$field;
	}
}

$model     = new FakeModel();
$validator = new \Phalcon\Mvc\Model\Validator\Email(array('field' => 'email'));
var_export($validator->validate($model));
?>
--EXPECT--
false
