<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Di\Autowire;

class ResolveFifthClass
{
    public $autowired;

    public function resolveMethod(AutowiredInterface $autowired)
    {
        $this->autowired = $autowired;
    }
}
