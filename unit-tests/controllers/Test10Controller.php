<?php

class Test10Controller extends Phalcon\Mvc\Controller
{
	public function viewAction(People $people)
	{
		return $people;
	}
}