<?php

namespace Phalcon\Test\Models\Relations;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Row;

/**
 * Phalcon\Test\Models\Relations\RobotsParts
 *
 * @method static RobotsParts findFirst($parameters = null)
 * @method Row getRobots($parameters = null)
 *
 * @package Phalcon\Test\Models\Relations
 */
class RobotsParts extends Model
{
    public function initialize()
    {
        $this->belongsTo(
            'robots_id',
            __NAMESPACE__ . '\Robots',
            'id',
            [
                'alias' => 'Robots',
                'params' => [
                    'columns' => 'id,name'
                ]
            ]
        );
    }
}
