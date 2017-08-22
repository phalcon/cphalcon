<?php

namespace Cacheable;

class Parts extends Model
{

	public function initialize()
	{
		$this->hasMany('id', RobotsParts::class, 'robots_id', array(
			'alias' => 'RobotsParts'
		));
	}

}
