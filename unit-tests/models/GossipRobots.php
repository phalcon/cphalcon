<?php

class GossipRobots extends Phalcon\Mvc\Model
{

	public $trace;

	public function getSource()
	{
		return 'robots';
	}

	protected function _talk($completeMethod)
	{
		$method = explode('::', $completeMethod);
		if (!isset($this->trace[$method[1]][get_class($this)])) {
			$this->trace[$method[1]][get_class($this)] = 1;
		} else {
			$this->trace[$method[1]][get_class($this)]++;
		}
	}

	public function beforeValidation()
	{
		$this->_talk(__METHOD__);
	}

	public function beforeValidationOnUpdate()
	{
		$this->_talk(__METHOD__);
	}

	public function afterValidationOnUpdate()
	{
		$this->_talk(__METHOD__);
	}

	public function validation()
	{
		$this->_talk(__METHOD__);
	}

	public function afterValidation()
	{
		$this->_talk(__METHOD__);
	}

	public function beforeSave()
	{
		$this->_talk(__METHOD__);
	}

	public function beforeUpdate()
	{
		$this->_talk(__METHOD__);
	}

	public function afterUpdate()
	{
		$this->_talk(__METHOD__);
	}

	public function afterSave()
	{
		$this->_talk(__METHOD__);
	}

	public function beforeCreate()
	{
		$this->_talk(__METHOD__);
		return false;
	}

	public function beforeDelete()
	{
		$this->_talk(__METHOD__);
		return false;
	}

	public function notSaved()
	{
		$this->_talk(__METHOD__);
		return false;
	}

}