<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Di\Autowire;

class ResolvedFirstClass
{
    /**
     * @var AutowiredInterface
     */
    public $autowired;

    /**
     * ResolvedFirstClass constructor.
     */
    public function __construct(AutowiredInterface $autowired)
    {
        $this->autowired = $autowired;
    }
}
