<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Autowire;

use Phalcon\Di\AutowireTypesStaticProviderInterface;

class ResolvedFourthClass implements AutowireTypesStaticProviderInterface
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

    public static function getAutowireTypes(): array
    {
        return [
            AutowiredInterface::class => AutowiredSecond::class,
        ];
    }
}
