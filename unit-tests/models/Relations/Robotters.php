<?php

use Phalcon\Mvc\Model;

/**
 * Robotters
 *
 * "robotters" is robots in danish
 */
class Robotters extends Model
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
			'deleted' => 'theDeleted',
			'text' => 'theText',
		);
	}

	public function initialize()
	{
		$this->hasMany('code', 'RobottersDeles', 'robottersCode', array(
			'foreignKey' => true
		));
	}
}
