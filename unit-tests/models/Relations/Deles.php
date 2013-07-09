<?php

/**
 * Deles
 *
 * Deles is "parts" in danish
 */
class Deles extends Phalcon\Mvc\Model
{

	public function getSource()
	{
		return 'parts';
	}

	public function columnMap()
	{
		return array(
			'id' => 'code',
			'name' => 'theName',
		);
	}

	public function initialize()
	{
		$this->hasMany('code', 'RobottersDeles', 'delesCode', array(
			'foreignKey' => array(
				'message' => 'Deles cannot be deleted because is referenced by a Robotter'
			)
		));
	}

}