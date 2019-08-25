<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Snapshot;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Behavior\SoftDelete;
use Phalcon\Mvc\Model\Behavior\Timestampable;

/**
 * @property int    $id
 * @property string $email
 * @property string $status
 * @property string $created_at
 */
class Subscribers extends Model
{
    public function initialize()
    {
        $this->setSource('subscriptores');

        $this->keepSnapshots(true);

        $this->addBehavior(
            new Timestampable(
                [
                    'beforeCreate' => [
                        'field'  => 'created_at',
                        'format' => 'Y-m-d H:i:s',
                    ],
                ]
            )
        );

        $this->addBehavior(
            new SoftDelete(
                [
                    'field' => 'status',
                    'value' => 'D',
                ]
            )
        );
    }
}
