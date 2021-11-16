<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models\Some;

use Phalcon\Mvc\Model;

class RobotsParts extends Model
{
    public function initialize()
    {
        $this->setSource('robots_parts');

        $this->belongsTo(
            'parts_id',
            Parts::class,
            'id',
            [
                'foreignKey' => true,
            ]
        );

        $this->belongsTo(
            'robots_id',
            Robots::class,
            'id',
            [
                'foreignKey' => [
                    'message' => 'The robot code does not exist',
                ],
            ]
        );
    }
}
