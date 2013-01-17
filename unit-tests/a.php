<?php

class Criteria extends Phalcon\Mvc\Model\Criteria
{

    public function execute()
    {
        $model = $this->_model;
        $resultset = $model::find($this->getParams());
        return $resultset;
    }
}

class Users extends Phalcon\Mvc\Model
{
    public static function query($di=null)
    {
        $c = new Criteria();
        $c->setModelName(get_called_class());
        return $c;
    }
}

function getBinds()
{
    $model = Users::query();
    $binds = $model->execute();
    $data  = array(1,2,3,4);
    return $data;
}

var_dump(getBinds());