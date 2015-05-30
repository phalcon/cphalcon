<?php

namespace News;

use Phalcon\Mvc\Model\Behavior\Timestampable;
use Phalcon\Mvc\Model\Behavior\SoftDelete;
use Phalcon\Mvc\Model\Behavior\Blameable;

class Subscribers extends \Phalcon\Mvc\Model
{

	public function getSource()
	{
		return 'subscriptores';
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

		$this->addBehavior(new Blameable());

		$this->keepSnapshots(true);
	}

}
