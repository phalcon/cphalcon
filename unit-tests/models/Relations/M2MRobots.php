<?php

class M2MRobots extends \Phalcon\Mvc\Model
{
	public function initialize()
	{
		$this->hasManyToMany('id', 'M2MRobotsParts', 'robots_id', 'parts_id', 'M2MParts', 'id');
	}

	public function getSource()
	{
		return 'm2m_robots';
	}
}
