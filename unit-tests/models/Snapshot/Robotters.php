<?php

namespace Snapshot;

class Robotters extends \Phalcon\Mvc\Model
{
	public function getSource()
	{
		return 'robots';
	}

	public function columnMap()
	{
		return array(
			'id' => 'code',
			'name' => 'theName',
			'type' => 'theType',
			'year' => 'theYear',
			'datetime' => 'theDatetime',
			'text' => 'theText'
		);
	}

	public function initialize()
	{
		$this->hasMany('code', 'RobottersDeles', 'robottersCode');
		$this->keepSnapshots(true);
	}

}