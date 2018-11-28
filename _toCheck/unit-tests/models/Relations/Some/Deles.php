<?php

namespace Some;

/**
 * Deles
 *
 * Deles is "parts" in danish
 */
class Deles extends \Phalcon\Mvc\Model
{

    public function getSource()
    {
        return 'parts';
    }

    public function columnMap()
    {
        return [
            'id'   => 'code',
            'name' => 'theName',
        ];
    }

    public function initialize()
    {
        $this->hasMany('code', 'Some\RobottersDeles', 'delesCode', [
            'foreignKey' => [
                'message' => 'Deles cannot be deleted because is referenced by a Robotter',
            ],
        ]);
    }

}
