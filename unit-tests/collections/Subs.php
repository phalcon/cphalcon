<?php

use Phalcon\Mvc\Collection\Behavior\Timestampable;
use Phalcon\Mvc\Collection\Behavior\SoftDelete;

class Subs extends \Phalcon\Mvc\Collection
{

	public function getSource()
	{
		return 'subs';
	}

	public function initialize()
	{
		$this->addBehavior(new Timestampable(array(
			'beforeCreate' => array(
				'field' => 'created_at',
				'format' => 'Y-m-d H:i:s'
			)
		)));

		$this->addBehavior(new SoftDelete(array(
			'field' => 'status',
			'value' => 'D'
		)));
	}

}
