<?php

namespace Snapshot;

class RobotsParts extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->belongsTo('robots_id', Robots::class, 'id');
		$this->belongsTo('parts_id', Parts::class, 'id');
	}

}
