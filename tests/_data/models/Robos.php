<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Test\ModelRepositories\RobosRepository;

/**
 * Robos
 *
 * "Robôs" is robots in portuguese
 * 
 * @author David Napierata
 *
 * @package Phalcon\Test\Models
 */
class Robos extends Model
{
	public static function getRepositoryClass()
	{
		return RobosRepository::class;
	}
}
