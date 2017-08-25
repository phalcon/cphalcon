<?php

namespace Phalcon\Test\Models\Some;

use Phalcon\Test\ModelRepositories\Some\RobotsRepository;

class Robots extends \Phalcon\Mvc\Model
{
    public function getSource()
    {
        return 'robots';
    }

    public static function getRepositoryClass()
    {
        return RobotsRepository::class;
    }

    public function getRobotsParts($arguments = null)
    {
        return $this->getRelated(RobotsParts::class, $arguments);
    }
}
