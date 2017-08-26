<?php

namespace Phalcon\Test\Models\Some;

use Phalcon\Test\ModelRepositories\Some\DelesRepository;

/**
 * Deles
 *
 * Deles is "parts" in danish
 */
class Deles extends \Phalcon\Mvc\Model
{
    public static function getRepositoryClass()
    {
        return DelesRepository::class;
    }
}
