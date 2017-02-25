<?php

namespace Phalcon\Test\Collections;

use Phalcon\Mvc\Collection;
use Phalcon\Mvc\Collection\Behavior\SoftDelete;
use Phalcon\Mvc\Collection\Behavior\Timestampable;

/**
 * Subs Collection
 *
 * @method static Subs[] find(array $parameters = null)
 * @method static Subs findFirst(array $parameters = null)
 *
 * @property \MongoId _id
 * @property string email
 * @property string status
 * @property string created_at
 *
 * @package Phalcon\Test\Collections
 */
class Subs extends Collection
{
    public function getSource()
    {
        return 'subs';
    }

    public function initialize()
    {
        $this->addBehavior(new Timestampable([
            'beforeCreate' => [
                'field'  => 'created_at',
                'format' => 'Y-m-d H:i:s'
            ]
        ]));

        $this->addBehavior(new SoftDelete([
            'field' => 'status',
            'value' => 'D'
        ]));
    }
}
