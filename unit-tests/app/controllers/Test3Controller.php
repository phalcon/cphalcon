<?php

class Test3Controller extends Phalcon\Controller
{

	public function indexAction()
	{

	}

	public function otherAction()
	{

	}

	public function anotherAction()
	{
		return 100;
	}

	public function coolvarAction()
	{
		$this->view->setVar("a_cool_var", "got-the-life");
	}

	public function queryAction()
	{
		$robot = Robots::findFirst();
		$this->view->setVar("name", $robot->name);
	}

}