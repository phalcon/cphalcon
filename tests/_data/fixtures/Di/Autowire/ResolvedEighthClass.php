<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Di\Autowire;

class ResolvedEighthClass
{
    /**
     * @var AutowiredThird
     */
    public $autowired;

    public function __construct(AutowiredThird $autowired)
    {
        $this->autowired = $autowired;
    }
}
