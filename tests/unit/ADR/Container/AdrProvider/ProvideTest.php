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

namespace Phalcon\Tests\Unit\ADR\Container\AdrProvider;

use Phalcon\ADR\Container\AdrProvider;
use Phalcon\ADR\Responder\JsonResponder;
use Phalcon\Container\Container;
use Phalcon\Container\ContainerFactory;
use Phalcon\Contracts\ADR\Responder\Responder;
use Phalcon\Contracts\Container\Service\Provider;
use Phalcon\Logger\Logger;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ProvideTest extends AbstractUnitTestCase
{
    private Container $container;

    protected function setUp(): void
    {
        $this->container = (new ContainerFactory())
            ->addProvider(new AdrProvider())
            ->newContainer();
    }

    /**
     * Unit Tests Phalcon\ADR\Container\AdrProvider :: provide() - registers aliases
     */
    public function testAdrContainerAdrProviderProvideRegistersAliases(): void
    {
        $names = [
            'dispatcher',
            'emitter',
            'eventsManager',
            'request',
            'responder',
            'response',
            'router',
        ];

        foreach ($names as $name) {
            $this->assertTrue(
                $this->container->has($name),
                "Service '{$name}' should be resolvable"
            );
        }
    }

    /**
     * Unit Tests Phalcon\ADR\Container\AdrProvider :: provide() - registers contracts
     */
    public function testAdrContainerAdrProviderProvideRegistersContracts(): void
    {
        $contracts = [
            'Phalcon\\Contracts\\ADR\\Dispatcher',
            'Phalcon\\Contracts\\ADR\\Emitter\\Emitter',
            'Phalcon\\Contracts\\ADR\\Responder\\Responder',
            'Phalcon\\Contracts\\ADR\\Router\\Router',
            'Phalcon\\Contracts\\Events\\Manager',
            'Phalcon\\Contracts\\Http\\AttributeRequest',
            'Phalcon\\Contracts\\Logger\\Logger',
            'Phalcon\\Http\\ResponseInterface',
        ];

        foreach ($contracts as $contract) {
            $this->assertTrue(
                $this->container->has($contract),
                "Contract '{$contract}' should be resolvable"
            );
        }
    }

    /**
     * Unit Tests Phalcon\ADR\Container\AdrProvider :: provide() - default logger
     */
    public function testAdrContainerAdrProviderProvideResolvesDefaultLogger(): void
    {
        $this->assertInstanceOf(
            Logger::class,
            $this->container->get('Phalcon\\Contracts\\Logger\\Logger')
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Container\AdrProvider :: provide() - default responder
     */
    public function testAdrContainerAdrProviderProvideResolvesDefaultResponder(): void
    {
        $this->assertInstanceOf(
            JsonResponder::class,
            $this->container->get(Responder::class)
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Container\AdrProvider :: implements Provider
     */
    public function testAdrContainerAdrProviderProvideYieldsProvider(): void
    {
        $this->assertInstanceOf(Provider::class, new AdrProvider());
    }
}
