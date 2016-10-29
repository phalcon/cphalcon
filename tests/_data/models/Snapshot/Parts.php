<?php

namespace Phalcon\Test\Models\Snapshot;

class Parts extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        $this->hasMany('id', RobotsParts::class, 'robots_id');
        $this->keepSnapshots(true);
    }
}
