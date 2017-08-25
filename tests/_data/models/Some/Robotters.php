<?php

namespace Phalcon\Test\Models\Some;

use Phalcon\Test\ModelRepositories\Some\RobottersRepository;

/**
 * Robotters
 *
 * "robotters" is robots in danish
 */
class Robotters extends \Phalcon\Mvc\Model
{
    public function columnMap()
    {
        return array(
            'id' => 'code',
            'name' => 'theName',
            'type' => 'theType',
            'year' => 'theYear',
            'datetime' => 'theDatetime',
            'deleted' => 'theDeleted',
            'text' => 'theText'
        );
    }

    public static function getRepositoryClass()
    {
        return RobottersRepository::class;
    }

    public function initialize()
    {
        $this->setSource('robots');
    }

    public function getRobottersDeles($arguments = null)
    {
        return $this->getRelated(RobottersDeles::class, $arguments);
    }
}
