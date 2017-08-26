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
    public function columnMap()
    {
        return array(
            'id' => 'code',
            'robots_id' => 'robottersCode',
            'parts_id' => 'delesCode',
        );
    }

    public static function getRepositoryClass()
    {
        return RobottersDelesRepository::class;
    }
}
