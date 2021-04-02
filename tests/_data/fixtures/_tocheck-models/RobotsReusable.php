<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

class RobotsReusable extends Model
{
    public function initialize()
    {
        $this->setSource('robots');

        $this->hasMany(
            'id',
            RobotsParts::class,
            'robots_id',
            [
                'alias'      => 'robotsParts',
                'foreignKey' => true,
                'reusable'   => true,
            ]
        );
    }
}
