<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Relations;

use Phalcon\Mvc\Model;

class RelationsRobotsParts extends Model
{
    public function initialize()
    {
        $this->belongsTo('parts_id', RelationsParts::class, 'id', [
            'foreignKey' => true,
        ]);
        $this->belongsTo('robots_id', RelationsRobots::class, 'id', [
            'foreignKey' => [
                'message' => 'The robot code does not exist',
            ],
        ]);
    }

    public function getSource(): string
    {
        return 'robots_parts';
    }
}
