<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Test\ModelRepositories\RobottersDelesRepository;

/**
 * RobottersDeles
 *
 * This model is an intermediate table for "Robotters" and "Deles"
 */
class RobottersDeles extends Model
{
    public static function getRepositoryClass()
    {
        return RobottersDelesRepository::class;
    }
}
