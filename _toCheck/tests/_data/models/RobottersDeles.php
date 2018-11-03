<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * RobottersDeles
 *
 * This model is an intermediate table for "Robotters" and "Deles"
 */
class RobottersDeles extends Model
{
    public function getSource()
    {
        return 'robots_parts';
    }

    public function columnMap()
    {
        return [
            'id' => 'code',
            'robots_id' => 'robottersCode',
            'parts_id' => 'delesCode',
        ];
    }

    public function initialize()
    {
        $this->belongsTo(
            'delesCode',
            Deles::class,
            'code',
            [
                'foreignKey' => true
            ]
        );

        $this->belongsTo(
            'robottersCode',
            Robotters::class,
            'code',
            [
                'foreignKey' => [
                    'message' => 'The robotters code does not exist'
                ]
            ]
        );
    }
}
