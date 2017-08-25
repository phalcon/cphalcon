<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Test\ModelRepositories\DelesRepository;

/**
 * Deles
 *
 * Deles is "parts" in danish
 */
class Deles extends Model
{
    public function initialize()
    {
        $this->setSource('parts');
    }

    public function columnMap()
    {
        return [
            'id' => 'code',
            'name' => 'theName',
        ];
    }

    public static function getRepositoryClass()
    {
        return DelesRepository::class;
    }
}
