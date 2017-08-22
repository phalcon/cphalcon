<?php

class Robots extends Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', RobotsParts::class, 'robots_id', array(
			'foreignKey' => true
		));
	}

}
