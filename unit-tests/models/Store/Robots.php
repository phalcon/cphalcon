<?php

namespace Store;

class Robots extends \Phalcon\Mvc\Model
{

	public function initialize()
	{

		$this->setConnectionService('dbOne');

		$this->hasMany('id', 'Store\RobotsParts', 'robots_id', array(
			'alias' => 'RobotParts'
		));
	}

}