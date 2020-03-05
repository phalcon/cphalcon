<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Cacheable;

use Phalcon\Mvc\Model as PhalconModel;

class RobotsParts extends PhalconModel
{
    public function initialize()
    {
        $this->belongsTo(
            'robots_id',
            Robots::class,
            'id',
            [
                'alias' => 'Robots',
            ]
        );

        $this->belongsTo(
            'parts_id',
            Parts::class,
            'id',
            [
                'alias' => 'Parts',
            ]
        );
    }
}
