<?php

namespace Cacheable;

class RobotsParts extends Model
{
	public function initialize()
	{
		$this->belongsTo('robots_id', 'Cacheable\Robots', 'id', array(
			'alias' => 'Robots'
		));
		$this->belongsTo('parts_id', 'Cacheable\Parts', 'id', array(
			'alias' => 'Parts'
		));
	}
}