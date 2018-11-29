<?php

use Phalcon\Mvc\Controller;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Robots;

class Test10Controller extends Controller
{
    public function viewAction(People $people)
    {
        return $people;
    }

    public function multipleAction(People $people, Robots $robots)
    {
        return [$people, $robots];
    }
}
