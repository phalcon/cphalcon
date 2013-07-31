<?php

class Robots extends Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', 'RobotsParts', 'robots_id', array(
			'foreignKey' => true
		));
	}

}