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
		$this->belongsTo('parts_id', 'Some\Parts', 'id', array(
			'foreignKey' => true
		));
		$this->belongsTo('robots_id', 'Some\Robots', 'id', array(
			'foreignKey' => array(
				'message' => 'The robot code does not exist'
			)
		));
	}

	public function getParts($arguments=null)
	{
		return $this->getRelated('Some\Parts', $arguments);
	}

	public function getRobots($arguments=null)
	{
		return $this->getRelated('Some\Robots', $arguments);
	}

}