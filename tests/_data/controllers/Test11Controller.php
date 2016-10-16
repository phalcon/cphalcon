<?php

use Phalcon\Mvc\Controller;
use Phalcon\Mvc\Model\Binder\BindableInterface;
use Phalcon\Mvc\Model;

class Test11Controller extends Controller implements BindableInterface
{
    public function getModelName()
    {
        return [
            'people' => 'Phalcon\Test\Models\People',
            'robots' => 'Phalcon\Test\Models\Robots'
        ];
    }

    public function viewAction(Model $people)
    {
        return $people;
    }

    public function multipleAction(Model $people, Model $robots)
    {
        return [$people, $robots];
    }
}
