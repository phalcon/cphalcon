<?php

class RelationsRobots extends Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', 'RelationsRobotsParts', 'robots_id', array(
			'foreignKey' => true
		));
		$this->hasManyToMany('id', 'RelationsRobotsParts', 'robots_id', 'parts_id', 'RelationsParts', 'id');
	}

	public function getSource()
	{
		return 'robots';
	}

}