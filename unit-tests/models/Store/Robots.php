<?php

namespace Store;

class Robots extends \Phalcon\Mvc\Model
{

	public function initialize()
	{

		$this->setConnectionService('dbOne');

		$this->hasMany('id', RobotsParts::class, 'robots_id', array(
			'alias' => 'RobotParts'
		));
	}

}
