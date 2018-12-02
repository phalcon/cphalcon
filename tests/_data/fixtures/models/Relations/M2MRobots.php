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

class M2MRobots extends Model
{
    public function initialize()
    {
        $this->hasManyToMany('id', M2MRobotsParts::class, 'robots_id', 'parts_id', 'M2MParts', 'id');
    }

    public function getSource(): string
    {
        return 'm2m_robots';
    }
}
