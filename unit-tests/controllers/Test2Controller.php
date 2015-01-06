<?php

class Test2Controller extends Phalcon\Mvc\Controller
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

	public function anotherTwoAction($a, $b)
	{
		return $a+$b;
	}

	public function anotherThreeAction()
	{
		return $this->dispatcher->forward(
			array(
				'controller' => 'test2',
				'action' => 'anotherfour'
			)
		);
	}

	public function anotherFourAction()
	{
		return 120;
	}

	public function anotherFiveAction()
	{
		return $this->dispatcher->getParam('param1')+$this->dispatcher->getParam('param2');
	}

}
