<?php

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Controller;
use Phalcon\Mvc\Controller\BindModelInterface;

class Test9Controller extends Controller implements BindModelInterface
{
    public static function getModelName()
    {
        return 'Phalcon\Test\Models\People';
    }

    public function viewAction(Model $model)
    {
        return $model;
    }
}
