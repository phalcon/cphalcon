<?php

class Categories extends Phalcon\Mvc\Model
{

    public function initialize()
    {
        $this->addBehavior(new Phalcon\Mvc\Model\Behavior\NestedSet(array('hasManyRoots' => true)));
    }

}