<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\ADR\Dispatcher;

use Phalcon\ADR\Dispatcher;
use Phalcon\ADR\Exceptions\NotAnAction;
use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\Container\Ioc\IocContainer;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Events\Manager;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use stdClass;

final class DispatchTest extends AbstractUnitTestCase
{

    /**
     * Unit Tests Phalcon\ADR\Dispatcher :: dispatch() rejects a non-Action
     */
    public function testAdrDispatcherDispatchRejectsNonAction(): void
    {
        $dispatcher = new Dispatcher($this->containerReturning(new stdClass()), new Manager());

        $this->expectException(NotAnAction::class);

        $dispatcher->dispatch('NotAnAction', new Request());
    }
    /**
     * Unit Tests Phalcon\ADR\Dispatcher :: dispatch() resolves and runs the action
     */
    public function testAdrDispatcherDispatchRunsAction(): void
    {
        $action = new class implements Action {
            public function __invoke(AttributeRequest $request): ResponseInterface
            {
                return (new Response())->setContent('dispatched');
            }
        };

        $dispatcher = new Dispatcher($this->containerReturning($action), new Manager());

        $response = $dispatcher->dispatch('SomeAction', new Request());

        $this->assertSame('dispatched', $response->getContent());
    }

    private function containerReturning(object $service): IocContainer
    {
        return new class ($service) implements IocContainer {
            public function __construct(private object $service)
            {
            }

            public function getService(string $serviceName): object
            {
                return $this->service;
            }

            public function hasService(string $serviceName): bool
            {
                return true;
            }
        };
    }
}
