<?php

namespace Phalcon\Test\Models\Some;

use Phalcon\Test\ModelRepositories\Some\RobottersDelesRepository;

/**
 * RobottersDeles
 *
 * This model is an intermediate table for "Robotters" and "Deles"
 */
class RobottersDeles extends \Phalcon\Mvc\Model
{
    public static function getRepositoryClass()
    {
        return RobottersDelesRepository::class;
    }
}
