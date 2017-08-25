<?php

class RelationsRobotsParts extends Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->setSource('robots_parts');

		$this->belongsTo('parts_id', RelationsParts::class, 'id', array(
			'foreignKey' => true
		));
		$this->belongsTo('robots_id', RelationsRobots::class, 'id', array(
			'foreignKey' => array(
				'message' => 'The robot code does not exist'
			)
		));
	}

}
