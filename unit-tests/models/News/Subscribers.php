<?php

namespace News;

use Phalcon\Mvc\Model\Behavior\Timestampable;
use Phalcon\Mvc\Model\Behavior\SoftDelete;

class Subscribers extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->setSource('subscriptores');

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
