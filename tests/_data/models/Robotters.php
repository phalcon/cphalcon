<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\ModelRepositories\RobottersRepository;

/**
 * Robotters
 *
 * "robotters" is robots in danish
 *
 * @method static int countByTheType(string $type)
 * @method static Simple findByTheType(string $type)
 * @method static Simple findFirstByCode(string|int $code)
 *
 * @package Phalcon\Test\Models
 */
class Robotters extends Model
{
    public function columnMap()
    {
        return [
            'id' => 'code',
            'name' => 'theName',
            'type' => 'theType',
            'year' => 'theYear',
            'datetime' => 'theDatetime',
            'deleted' => 'theDeleted',
            'text' => 'theText',
        ];
    }

    public static function getRepositoryClass()
    {
        return RobottersRepository::class;
    }
}
