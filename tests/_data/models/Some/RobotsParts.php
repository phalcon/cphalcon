<?php

namespace Phalcon\Test\Models\Some;

use Phalcon\Test\ModelRepositories\Some\RobotsPartsRepository;

class RobotsParts extends \Phalcon\Mvc\Model
{
    public static function getRepositoryClass()
    {
        return RobotsPartsRepository::class;
    }

    public function initialize()
    {
        $this->setSource('robots_parts');
    }
}
