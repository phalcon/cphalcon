<?php

namespace Cacheable;

class Parts extends Model
{

	public function initialize()
	{
		$this->hasMany('id', 'Cacheable\RobotsParts', 'robots_id', array(
			'alias' => 'RobotsParts'
		));
	}

}