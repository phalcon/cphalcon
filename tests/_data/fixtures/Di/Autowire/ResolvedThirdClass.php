<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Di\Autowire;

class ResolvedThirdClass
{
    /**
     * @var AutowiredInterface
     */
    public $autowired;

    /**
     * @var string
     */
    public $test;

    /**
     * ResolvedFirstClass constructor.
     */
    public function __construct(AutowiredInterface $autowired, $test)
    {
        $this->autowired = $autowired;
        $this->test = $test;
    }
}
