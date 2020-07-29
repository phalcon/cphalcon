<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Di\Autowire;

use Phalcon\Di\AutowireTypesProviderInterface;

class ResolvedSixthClass implements AutowireTypesProviderInterface
{
    public $autowired;

    public function resolveMethod(AutowiredInterface $autowired)
    {
        $this->autowired = $autowired;
    }

    public function getAutowireTypes(): array
    {
        return [AutowiredInterface::class => AutowiredSecond::class];
    }
}
