<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Some;

use Phalcon\Mvc\Model\AbstractModel;

class RobottersDeles extends AbstractModel
{
    public function columnMap()
    {
        return [
            'id'        => 'code',
            'robots_id' => 'robottersCode',
            'parts_id'  => 'delesCode',
        ];
    }

    public function initialize()
    {
        $this->setSource('robots_parts');

        $this->belongsTo(
            'delesCode',
            Deles::class,
            'code',
            [
                'foreignKey' => true,
            ]
        );

        $this->belongsTo(
            'robottersCode',
            Robotters::class,
            'code',
            [
                'foreignKey' => [
                    'message' => 'The robotters code does not exist',
                ],
            ]
        );
    }
}
