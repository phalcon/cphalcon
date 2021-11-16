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
use Phalcon\Mvc\Model\Row;

/**
 * Phalcon\Tests\Models\Relations\RobotsParts
 *
 * @method static RobotsParts findFirst($parameters = null)
 * @method Row getRobots($parameters = null)
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
                'alias'  => 'Robots',
                'params' => [
                    'columns' => 'id,name',
                ],
            ]
        );
    }
}
