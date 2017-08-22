<?php

namespace Cacheable;

class RobotsParts extends Model
{
	public function initialize()
	{
		$this->belongsTo('robots_id', Robots::class, 'id', array(
			'alias' => 'Robots'
		));
		$this->belongsTo('parts_id', Parts::class, 'id', array(
			'alias' => 'Parts'
		));
	}
}
