<?php

use Phalcon\Mvc\Controller;
use Phalcon\Test\Models\People;

class Test10Controller extends Controller
{
    public function viewAction(People $people)
    {
        return $people;
    }
}
