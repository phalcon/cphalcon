<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Relations;

use Phalcon\Mvc\Model;

class RelationsRobots extends Model
{
    public function initialize()
    {
        $this->setSource('robots');

        $this->hasMany(
            'id',
            RelationsRobotsParts::class,
            'robots_id',
            [
                'foreignKey' => true,
            ]
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
}
