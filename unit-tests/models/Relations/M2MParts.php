<?php

class M2MParts extends Phalcon\Mvc\Model
{
	public function initialize()
	{
		$this->setSource('m2m_parts');
	}
}
