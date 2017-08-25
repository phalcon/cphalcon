<?php

class People extends Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->setSource("personas");
	}

}
