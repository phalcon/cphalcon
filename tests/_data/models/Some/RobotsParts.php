<?php

namespace Phalcon\Test\Models\Some;

class RobotsParts extends \Phalcon\Mvc\Model
{
    public function getSource()
    {
        return 'robots_parts';
    }

    public function initialize()
    {
        $this->belongsTo('parts_id', \Phalcon\Test\Models\Parts::class, 'id', array(
            'foreignKey' => true
        ));
        $this->belongsTo('robots_id', \Phalcon\Test\Models\Robots::class, 'id', array(
            'foreignKey' => array(
                'message' => 'The robot code does not exist'
            )
        ));
    }
}
