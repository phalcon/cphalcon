<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Store;

use Phalcon\Mvc\Model;

class RobotsParts extends Model
{
    public function initialize()
    {
        $this->setConnectionService('dbOne');

        $this->belongsTo(
            'parts_id',
            Parts::class,
            'id',
            [
                'alias' => 'Part',
            ]
        );

        $this->belongsTo(
            'robots_id',
            Robots::class,
            'id',
            [
                'alias' => 'Robot',
            ]
        );
    }
}
