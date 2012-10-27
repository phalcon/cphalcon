<?php

namespace Some;

class RobotsParts extends \Phalcon\Mvc\Model
{

	public function getSource()
	{
		return 'robots_parts';
	}

	public function initialize()
	{
		$this->belongsTo('parts_id', 'Parts', 'id', array(
			'foreignKey' => true
		));
		$this->belongsTo('robots_id', 'Robots', 'id', array(
			'foreignKey' => array(
				'message' => 'The robot code does not exist'
			)
		));
	}

}