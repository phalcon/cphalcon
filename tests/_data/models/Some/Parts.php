<?php

namespace Phalcon\Test\Models\Some;

use Phalcon\Test\ModelRepositories\Some\PartsRepository;

class Parts extends \Phalcon\Mvc\Model
{
    public function getSource()
    {
        return 'parts';
    }

    public static function getRepositoryClass()
    {
        return PartsRepository::class;
    }
}
