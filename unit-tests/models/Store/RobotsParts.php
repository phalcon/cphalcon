<?php

namespace Store;

class RobotsParts extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->setConnectionService('dbOne');

		$this->belongsTo('parts_id', Parts::class, 'id', array(
			'alias' => 'Part'
		));
		$this->belongsTo('robots_id', Robots::class, 'id', array(
			'alias' => 'Robot'
		));
	}

}
