<?php

namespace Boutique;

/**
 * Robotters
 *
 * "robotters" is robots in danish
 */
class Robotters extends \Phalcon\Mvc\Model
{

	/**
	 * @Primary
	 * @Identity
	 * @Column(type="integer", nullable=false, column="id")
	 */
	public $code;

	/**
	 * @Column(type="string", length=70, nullable=false, column="name")
	 */
	public $theName;

	/**
	 * @Column(type="string", length=32, nullable=false, column="type")
	 */
	public $theType;

	/**
	 * @Column(type="integer", nullable=false, column="year")
	 */
	public $theYear;

	public function getSource()
	{
		return 'robots';
	}

}