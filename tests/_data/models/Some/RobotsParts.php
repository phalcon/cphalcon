<?php

namespace Phalcon\Test\Models\Some;

use Phalcon\Test\ModelRepositories\Some\RobotsPartsRepository;

class RobotsParts extends \Phalcon\Mvc\Model
{
    public function getSource()
    {
        return 'robots_parts';
    }

    public static function getRepositoryClass()
    {
        return RobotsPartsRepository::class;
    }
}
