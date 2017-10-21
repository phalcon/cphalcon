<?php

namespace Phalcon\Test\Models\Relations;

use Phalcon\Mvc\Model;

/**
 * Phalcon\Test\Models\Relations\RelationsRobots
 *
 * @package Phalcon\Test\Models\Relations
 */
class RelationsRobots extends Model
{
    public function initialize()
    {
        $this->hasMany(
            'id',
            RelationsRobotsParts::class,
            'robots_id',
            ['foreignKey' => true]
        );

        $this->hasManyToMany(
            'id',
            RelationsRobotsParts::class,
            'robots_id',
            'parts_id',
            RelationsParts::class,
            'id'
        );
    }

    public function getSource()
    {
        return 'robots';
    }
}
