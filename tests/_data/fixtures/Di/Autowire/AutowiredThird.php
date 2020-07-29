<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Di\Autowire;

class AutowiredThird implements AutowiredInterface
{
    public $test;

    public function __construct($value = null)
    {
        if (!$value) {
            $this->test = $value;
        } else {
            $this->test = rand();
        }
    }
}
