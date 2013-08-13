<?php

class Test8Controller extends Phalcon\Mvc\Controller
{

	public function buggyAction()
	{
		throw new Exception("This is an uncaught exception");
	}

}