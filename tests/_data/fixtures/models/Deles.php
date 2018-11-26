<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Deles
 *
 * Deles is "parts" in danish
 */
class Deles extends Model
{
    public function getSource()
    {
        return 'parts';
    }

    public function columnMap()
    {
        return [
            'id' => 'code',
            'name' => 'theName',
        ];
    }

    public function initialize()
    {
        $this->hasMany(
            'code',
            RobottersDeles::class,
            'delesCode',
            [
                'foreignKey' => [
                    'message' => 'Deles cannot be deleted because is referenced by a Robotter'
                ]
            ]
        );
    }
}
