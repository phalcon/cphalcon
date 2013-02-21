<?php

namespace Snapshot;

class RobotsParts extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->belongsTo('robots_id', 'Snapshot\Robots', 'id');
		$this->belongsTo('parts_id', 'Snapshot\Parts', 'id');
	}

}