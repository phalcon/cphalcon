<?php

namespace Phalcon\Tests\Support\Models;

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
