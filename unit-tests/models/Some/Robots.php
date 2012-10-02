<?php

namespace Some;

class Robots extends \Phalcon\Mvc\Model
{

	public function getSource()
	{
		return 'robots';
	}

	public function initialize()
	{
		$this->hasMany('id', 'Some\RobotsParts', 'robots_id', array(
			'foreignKey' => true
		));
	}

	public function getRobotsParts()
	{
		return $this->getRelated('Some\RobotsParts');
	}

}