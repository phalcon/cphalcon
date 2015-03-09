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
	 * @Column(type="integer", nullable=false, mappedColumn="id")
	 */
	public $code;

	/**
	 * @Column(type="string", length=70, nullable=false, mappedColumn="id")
	 */
	public $theName;

	/**
	 * @Column(type="string", length=32, nullable=false, mappedColumn="id")
	 */
	public $theType;

	/**
	 * @Column(type="integer", nullable=false, mappedColumn="id")
	 */
	public $theYear;

	public function getSource()
	{
		return 'robots';
	}

}