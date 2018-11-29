<?php

namespace News;

use Phalcon\Mvc\Model\Behavior\SoftDelete;
use Phalcon\Mvc\Model\Behavior\Timestampable;

class Subscribers extends \Phalcon\Mvc\Model
{

    public function getSource()
    {
        return 'subscriptores';
    }

    public function initialize()
    {
        $this->addBehavior(new Timestampable([
            'beforeCreate' => [
                'field'  => 'created_at',
                'format' => 'Y-m-d H:i:s',
            ],
        ]));

        $this->addBehavior(new SoftDelete([
            'field' => 'status',
            'value' => 'D',
        ]));
    }

}
