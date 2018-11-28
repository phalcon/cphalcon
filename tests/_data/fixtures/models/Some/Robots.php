<?php

namespace Phalcon\Test\Models\Some;

class Robots extends \Phalcon\Mvc\Model
{
    public function getSource(): string
    {
        return 'robots';
    }

    public function initialize()
    {
        $this->hasMany('id', RobotsParts::class, 'robots_id', [
            'foreignKey' => true,
        ]);
    }

    public function getRobotsParts($arguments = null)
    {
        return $this->getRelated(RobotsParts::class, $arguments);
    }
}
