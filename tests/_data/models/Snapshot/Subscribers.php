<?php

namespace Phalcon\Test\Models\Snapshot;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Behavior\SoftDelete;
use Phalcon\Mvc\Model\Behavior\Timestampable;

/**
 * \Phalcon\Test\Models\Subscribers
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * @property int $id
 * @property string $email
 * @property string $status
 * @property string $created_at
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Subscribers extends Model
{
    public function getSource()
    {
        return 'subscriptores';
    }

    public function initialize()
    {
        $this->keepSnapshots(true);

        $this->addBehavior(new Timestampable([
            'beforeCreate' => [
                'field' => 'created_at',
                'format' => 'Y-m-d H:i:s'
            ]
        ]));

        $this->addBehavior(new SoftDelete([
            'field' => 'status',
            'value' => 'D'
        ]));
    }
}
