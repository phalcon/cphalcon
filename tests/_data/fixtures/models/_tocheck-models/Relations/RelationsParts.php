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

class RelationsParts extends Model
{
    public function initialize()
    {
        $this->setSource('parts');

        $this->hasMany(
            'id',
            RelationsRobotsParts::class,
            'parts_id',
            [
                'foreignKey' => [
                    'message' => 'Parts cannot be deleted because is referenced by a Robot',
                ],
            ]
        );

        $this->hasOneThrough(
            'id',
            RelationsRobotsParts::class,
            'parts_id',
            'robots_id',
            RelationsRobots::class,
            'id',
            [
                'alias' => 'oneRobot',
            ]
        );
    }
}
