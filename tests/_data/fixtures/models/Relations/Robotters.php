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

class Robotters extends Model
{
    public function getSource(): string
    {
        return 'robots';
    }

    public function columnMap()
    {
        return [
            'id'       => 'code',
            'name'     => 'theName',
            'type'     => 'theType',
            'year'     => 'theYear',
            'datetime' => 'theDatetime',
            'deleted'  => 'theDeleted',
            'text'     => 'theText',
        ];
    }

    public function initialize()
    {
        $this->hasMany('code', RobottersDeles::class, 'robottersCode', [
            'foreignKey' => true,
        ]);
    }
}
