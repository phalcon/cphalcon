<?php

namespace Store;

class Parts extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->setConnectionService('dbTwo');

		$this->hasMany('id', 'Some\RobotsParts', 'parts_id', array(
			'alias' => 'RobotParts'
		));
	}

}