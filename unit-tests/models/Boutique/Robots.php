<?php

namespace Boutique;

class Robots extends \Phalcon\Mvc\Model
{

	/**
	 * @Primary
	 * @Identity
	 * @Column(type="integer", nullable=false)
	 */
	public $id;

	/**
	 * @Column(type="string", length=70, nullable=false)
	 */
	public $name;

	/**
	 * @Column(type="string", length=32, nullable=false, default='mechanical')
	 */
	public $type;

	/**
	 * @Column(type="integer", nullable=false, default=1900)
	 */
	public $year;

	/**
	 * @Column(type="datetime", nullable=false)
	 */
	public $datetime;

	/**
	 * @Column(type="text", nullable=false)
	 */
	public $text;
}