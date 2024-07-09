<?php

declare(strict_types=1);

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model;

class RbTestModel extends Model
{
    public $id;

    public $name; // varchar 10

    public function initialize()
    {
        $this->setSource('co_rb_test_model');
    }
}
