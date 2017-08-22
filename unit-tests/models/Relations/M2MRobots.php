<?php

class M2MRobots extends \Phalcon\Mvc\Model
{
	public function initialize()
	{
		$this->hasManyToMany('id', M2MRobotsParts::class, 'robots_id', 'parts_id', M2MParts::class, 'id');
	}

	public function getSource()
	{
		return 'm2m_robots';
	}
}
