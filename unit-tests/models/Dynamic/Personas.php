<?php

namespace Dynamic;

/**
 * Personas
 *
 * Personas is people in spanish
 */
class Personas extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->useDynamicUpdate(true);
	}

}