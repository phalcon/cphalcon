--TEST--
Unhelpful fatal error with custom validator - https://github.com/phalcon/cphalcon/issues/1664
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class Dollar extends \Phalcon\Mvc\Model\Validator implements \Phalcon\Mvc\Model\ValidatorInterface
{
	public function validate($model)
	{
		$field = $this->getOption('field');
		$value = $model->$field;

		return (preg_match('/^\d+(\.\d{2})?$/', $value)) ? true : false;
	}
}

class Test extends \Phalcon\Mvc\Model
{
	public $value = 'aaa';

	public function validation()
	{
		$this->validate(new Dollar(array('field' => 'value')));
		return $this->validationHasFailed() ? false : true;
	}
}

$di   = new \Phalcon\Di\FactoryDefault();
$test = new Test();
try {
	$test->validation();
}
catch (LogicException $e) {
	echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECT--
Validator 'Dollar' returned false but did not call appendMessage()
