<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models\Relations;

use Phalcon\Mvc\Model;

class M2MRobots extends Model
{
    public function initialize()
    {
        $this->setSource('m2m_robots');

        $this->hasManyToMany(
            'id',
            M2MRobotsParts::class,
            'robots_id',
            'parts_id',
            M2MParts::class,
            'id',
            ['alias' => 'M2MParts']
        );
    }
}
