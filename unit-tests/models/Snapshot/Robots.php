<?php

namespace Snapshot;

class Robots extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', 'Snapshot\RobotsParts', 'robots_id');
		$this->keepSnapshots(true);
	}

}