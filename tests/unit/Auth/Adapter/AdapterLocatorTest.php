<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Adapter;

use Phalcon\Auth\Adapter\AdapterLocator;
use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Config\StreamAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Adapter\Stream;
use Phalcon\Auth\Exception;
use Phalcon\Container\Container;
use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Encryption\Security\Security as SecurityContract;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class AdapterLocatorTest extends AbstractUnitTestCase
{
    private Container $container;

    protected function setUp(): void
    {
        $this->container = new Container();
        $security        = new Security();

        $this->container->set(SecurityContract::class, fn () => $security);
        $this->container->set(MemoryAdapterConfig::class, fn () => new MemoryAdapterConfig());
        $this->container->set(StreamAdapterConfig::class, fn () => new StreamAdapterConfig('unused.json'));
    }

    public function testNewInstanceReturnsMemory(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $factory = new AdapterLocator($this->container);
        $adapter = $factory->newInstance('memory');

        $this->assertInstanceOf(Memory::class, $adapter);
        $this->assertInstanceOf(Adapter::class, $adapter);
    }

    public function testNewInstanceReturnsStream(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $factory = new AdapterLocator($this->container);
        $adapter = $factory->newInstance('stream');

        $this->assertInstanceOf(Stream::class, $adapter);
    }

    public function testCustomMappingHonored(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $factory = new AdapterLocator(
            $this->container,
            ['custom' => Memory::class]
        );

        $this->assertInstanceOf(Memory::class, $factory->newInstance('custom'));
    }

    public function testRegisterAddsMapping(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $factory = new AdapterLocator($this->container);
        $factory->register('alt', Memory::class);

        $this->assertInstanceOf(Memory::class, $factory->newInstance('alt'));
    }

    public function testRegisterRejectsNonAdapterClass(): void
    {
        $this->expectException(Exception::class);

        $factory = new AdapterLocator($this->container);
        $factory->register('bad', stdClass::class);
    }

    public function testUnknownNameThrows(): void
    {
        $this->expectException(Exception::class);

        $factory = new AdapterLocator($this->container);
        $factory->newInstance('unknown_adapter');
    }
}
