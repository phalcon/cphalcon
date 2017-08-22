<?php

namespace Snapshot;

class Robots extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', RobotsParts::class, 'robots_id');
		$this->keepSnapshots(true);
	}

}
