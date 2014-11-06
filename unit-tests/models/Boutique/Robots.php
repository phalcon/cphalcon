<?php

namespace Boutique;

class Robots extends \Phalcon\Mvc\Model
{

	/**
	 * @Primary
	 * @Identity
	 * @Column(type="integer", size=10, nullable=false)
	 */
	public $id;

	/**
	 * @Column(type="string", size=70, nullable=false, column="name")
	 */
	public $robotName;

	/**
	 * @Column(type="string", size=32, nullable=false)
	 */
	public $type;

	/**
	 * @Column(type="integer", size=11, nullable=false)
	 */
	public $year;

}