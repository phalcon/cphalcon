<?php

class Test9Controller extends Phalcon\Mvc\Controller
{
	public function viewAction(People $people)
	{
		return $people;
	}
}