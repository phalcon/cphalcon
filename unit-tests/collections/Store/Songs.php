<?php

namespace Store;

class Songs extends \Phalcon\Mvc\Collection
{

	protected function _trace($method)
	{
		if(!isset($this->trace[$method])){
			$this->trace[$method] = 1;
		} else {
			$this->trace[$method]++;
		}
	}

	protected function beforeValidation()
	{
		$this->_trace(__METHOD__);
	}

	protected function beforeValidationOnCreate()
	{
		$this->_trace(__METHOD__);
	}

	protected function afterValidationOnCreate()
	{
		$this->_trace(__METHOD__);
	}

	protected function afterValidationOnUpdate()
	{
		$this->_trace(__METHOD__);
	}

	protected function afterValidation()
	{
		$this->_trace(__METHOD__);
	}

	protected function beforeSave()
	{
		$this->_trace(__METHOD__);
	}

	protected function beforeCreate()
	{
		$this->_trace(__METHOD__);
	}

	protected function beforeUpdate()
	{
		$this->_trace(__METHOD__);
	}

	protected function afterCreate()
	{
		$this->_trace(__METHOD__);
	}

	protected function afterUpdate()
	{
		$this->_trace(__METHOD__);
	}

	protected function afterSave()
	{
		$this->_trace(__METHOD__);
	}

}