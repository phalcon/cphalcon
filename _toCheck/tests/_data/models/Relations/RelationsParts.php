<?php

class RelationsParts extends Phalcon\Mvc\Model
{

    public function initialize()
    {
        $this->hasMany('id', 'RelationsRobotsParts', 'parts_id', [
            'foreignKey' => [
                'message' => 'Parts cannot be deleted because is referenced by a Robot',
            ],
        ]);
    }

    public function getSource()
    {
        return 'parts';
    }

}
