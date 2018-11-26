<?php

namespace Phalcon\Test\Models\Some;

/**
 * Robotters
 *
 * "robotters" is robots in danish
 */
class Robotters extends \Phalcon\Mvc\Model
{
    public function getSource()
    {
        return 'robots';
    }

    public function columnMap()
    {
        return array(
            'id' => 'code',
            'name' => 'theName',
            'type' => 'theType',
            'year' => 'theYear',
            'datetime' => 'theDatetime',
            'deleted' => 'theDeleted',
            'text' => 'theText'
        );
    }

    public function initialize()
    {
        $this->hasMany('code', RobottersDeles::class, 'robottersCode', array(
            'foreignKey' => true
        ));
    }

    public function getRobottersDeles($arguments = null)
    {
        return $this->getRelated(RobottersDeles::class, $arguments);
    }
}
