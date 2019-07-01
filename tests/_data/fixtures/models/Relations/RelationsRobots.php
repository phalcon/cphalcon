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

use Phalcon\Mvc\Model\AbstractModel;

class RelationsRobots extends AbstractModel
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
