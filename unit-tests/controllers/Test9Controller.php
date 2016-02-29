<?php

use Phalcon\Mvc\Model;

class Test9Controller extends Phalcon\Mvc\Controller implements Phalcon\Mvc\Controller\BindModelInterface
{
	public static function getModelName()
	{
		return 'People';
	}

	public function viewAction(Model $model)
	{
		return $model;
	}
}