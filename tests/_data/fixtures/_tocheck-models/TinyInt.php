<?php

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model;

class TinyInt extends Model
{
    public $id;
    public $test;

    public function initialize()
    {
        $this->setSource("tiny_int_test");
    }
}
