<?php

namespace Store;

class RobotsParts extends \Phalcon\Mvc\Model
{

    public function initialize()
    {
        $this->setConnectionService('dbOne');

        $this->belongsTo('parts_id', 'Store\Parts', 'id', [
            'alias' => 'Part',
        ]);
        $this->belongsTo('robots_id', 'Store\Robots', 'id', [
            'alias' => 'Robot',
        ]);
    }

}
