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
    public function columnMap()
    {
        return array(
            'id' => 'code',
            'name' => 'theName',
        );
    }

    public static function getRepositoryClass()
    {
        return DelesRepository::class;
    }

    public function initialize()
    {
        $this->setSource('parts');
    }
}
