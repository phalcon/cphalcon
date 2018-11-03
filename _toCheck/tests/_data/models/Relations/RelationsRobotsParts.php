<?php

namespace Phalcon\Test\Models\Relations;

use Phalcon\Mvc\Model;

/**
 * Phalcon\Test\Models\Relations\RelationsRobotsParts
 *
 * @package Phalcon\Test\Models\Relations
 */
class RelationsRobotsParts extends Model
{
    public function initialize()
    {
        $this->belongsTo(
            'parts_id',
            RelationsParts::class,
            'id',
            ['foreignKey' => true]
        );

        $this->belongsTo(
            'robots_id',
            RelationsRobots::class,
            'id',
            ['foreignKey' => ['message' => 'The robot code does not exist']]
        );
    }

    public function getSource()
    {
        return 'robots_parts';
    }
}
