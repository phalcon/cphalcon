<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

class TinyIntTest extends Model
{
    public $id;
    public $test;

    public function initialize()
    {
        $this->setSource("tiny_int_test");
    }
}
