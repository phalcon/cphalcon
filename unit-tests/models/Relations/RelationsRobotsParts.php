<?php

class RelationsRobotsParts extends Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->belongsTo('parts_id', 'RelationsParts', 'id', array(
			'foreignKey' => true
		));
		$this->belongsTo('robots_id', 'RelationsRobots', 'id', array(
			'foreignKey' => array(
				'message' => 'The robot code does not exist'
			)
		));
	}

	public function getSource()
	{
		return 'robots_parts';
	}

}