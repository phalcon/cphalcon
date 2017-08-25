<?php

namespace Some;

class Robots extends \Phalcon\Mvc\Model
{
	public function initialize()
	{
		$this->setSource('robots');

		$this->hasMany('id', RobotsParts::class, 'robots_id', array(
			'foreignKey' => true
		));
	}

	public function getRobotsParts($arguments=null)
	{
		return $this->getRelated(RobotsParts::class, $arguments);
	}

}
