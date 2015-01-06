<?php

namespace Some;

/**
 * Robotters
 *
 * "robotters" is robots in danish
 */
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
			'year' => 'theYear'
		);
	}

	public function initialize()
	{
		$this->hasMany('code', 'Some\RobottersDeles', 'robottersCode', array(
			'foreignKey' => true
		));
	}

	public function getRobottersDeles($arguments=null)
	{
		return $this->getRelated('Some\RobottersDeles', $arguments);
	}

}