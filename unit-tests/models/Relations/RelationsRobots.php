<?php

class RelationsRobots extends Phalcon\Mvc\Model
{
	public function initialize()
	{
		$this->setSource('robots');

		$this->hasMany('id', RelationsRobotsParts::class, 'robots_id', array(
			'foreignKey' => true
		));
		$this->hasManyToMany('id', RelationsRobotsParts::class, 'robots_id', 'parts_id', RelationsParts::class, 'id');
	}
}
