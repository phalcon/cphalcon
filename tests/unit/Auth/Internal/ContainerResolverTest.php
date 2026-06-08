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

namespace Phalcon\Tests\Unit\Auth\Internal;

use Phalcon\Auth\Access\Auth as AuthGate;
use Phalcon\Auth\Internal\ContainerResolver;
use Phalcon\Container\Container;
use Phalcon\Container\Exceptions\Exception as ContainerException;
use Phalcon\Di\Di;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use stdClass;
use TypeError;

final class ContainerResolverTest extends AbstractUnitTestCase
{
    public function testEnsureContainerRejectsForeignObject(): void
    {
        $this->expectException(TypeError::class);

        ContainerResolver::ensureContainer(new stdClass());
    }

    public function testRequireServiceFallsBackToShortNameOnDi(): void
    {
        $di = new Di();
        $di->set('request', fn () => new FakeRequest());

        $service = ContainerResolver::requireService(
            $di,
            ['Phalcon\\Http\\RequestInterface', 'request'],
            'Session guard'
        );

        $this->assertInstanceOf(FakeRequest::class, $service);
    }

    public function testRequireServiceThrowsContainerExceptionWhenNoCandidate(): void
    {
        $this->expectException(ContainerException::class);
        $this->expectExceptionMessage('Session guard requires service');

        ContainerResolver::requireService(
            new Container(),
            ['Phalcon\\Http\\RequestInterface', 'request'],
            'Session guard'
        );
    }

    public function testResolveFreshBuildsUnregisteredExistingClassOnDi(): void
    {
        $instance = ContainerResolver::resolveFresh(new Di(), AuthGate::class);

        $this->assertInstanceOf(AuthGate::class, $instance);
    }

    public function testResolveFreshThrowsContainerExceptionForUnknownClassOnDi(): void
    {
        $this->expectException(ContainerException::class);

        ContainerResolver::resolveFresh(new Di(), 'NoSuch\\Class\\AtAll');
    }

    public function testResolveFreshYieldsFreshInstanceOnContainer(): void
    {
        $container = new Container();

        $this->assertNotSame(
            ContainerResolver::resolveFresh($container, AuthGate::class),
            ContainerResolver::resolveFresh($container, AuthGate::class)
        );
    }

    public function testServiceCandidatesDefaultsToFqnThenShortName(): void
    {
        $this->assertSame(
            ['Phalcon\\Http\\RequestInterface', 'request'],
            ContainerResolver::serviceCandidates(
                [],
                'request',
                'Phalcon\\Http\\RequestInterface',
                'request'
            )
        );
    }

    public function testServiceCandidatesHonorsOverride(): void
    {
        $this->assertSame(
            ['my_request'],
            ContainerResolver::serviceCandidates(
                ['services' => ['request' => 'my_request']],
                'request',
                'Phalcon\\Http\\RequestInterface',
                'request'
            )
        );
    }
}
