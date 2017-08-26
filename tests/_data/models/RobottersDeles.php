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
    public function columnMap()
    {
        return [
            'id' => 'code',
            'robots_id' => 'robottersCode',
            'parts_id' => 'delesCode',
        ];
    }

    public static function getRepositoryClass()
    {
        return RobottersDelesRepository::class;
    }
}
