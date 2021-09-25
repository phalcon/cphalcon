<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model;

class Deles extends Model
{
    public function columnMap()
    {
        return [
            'id'   => 'code',
            'name' => 'theName',
        ];
    }

    public function initialize()
    {
        $this->setSource('parts');

        $this->hasMany(
            'code',
            RobottersDeles::class,
            'delesCode',
            [
                'foreignKey' => [
                    'message' => 'Deles cannot be deleted because is referenced by a Robotter',
                ],
            ]
        );
    }
}
