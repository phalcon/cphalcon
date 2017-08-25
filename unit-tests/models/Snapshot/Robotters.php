<?php

namespace Snapshot;

class Robotters extends \Phalcon\Mvc\Model
{
	public function columnMap()
	{
		return array(
			'id' => 'code',
			'name' => 'theName',
			'type' => 'theType',
			'year' => 'theYear',
			'datetime' => 'theDatetime',
			'deleted' => 'theDeleted',
			'text' => 'theText'
		);
	}

	public function initialize()
	{
		$this->setSource('robots');

		$this->hasMany('code', \RobottersDeles::class, 'robottersCode');
		$this->keepSnapshots(true);
	}

}
