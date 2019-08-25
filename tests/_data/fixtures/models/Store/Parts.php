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

class Parts extends Model
{
    public function initialize()
    {
        $this->setConnectionService('dbTwo');

        $this->hasMany(
            'id',
            RobotsParts::class,
            'parts_id',
            [
                'alias' => 'RobotParts',
            ]
        );
    }
}
