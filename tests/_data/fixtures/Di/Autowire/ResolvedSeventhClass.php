<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Di\Autowire;

use Phalcon\Di\AutowireTypesStaticProviderInterface;

class ResolvedSeventhClass implements AutowireTypesStaticProviderInterface
{
    public $autowired;

    public function resolveMethod(AutowiredInterface $autowired)
    {
        $this->autowired = $autowired;
    }

    public static function getAutowireTypes(): array
    {
        return [AutowiredInterface::class => AutowiredSecond::class];
    }
}
