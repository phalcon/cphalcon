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

namespace Phalcon\Tests\Unit\Support;

use ArrayIterator;
use Countable;
use Exception;
use Phalcon\Di\Di;
use Phalcon\Support\AbstractLocator;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class AbstractLocatorTest extends AbstractUnitTestCase
{
    public function testSupportAbstractLocatorConstructorRegistersPassedServices(): void
    {
        $locator = $this->getLocator(new Di(), ['extra' => ArrayIterator::class]);

        // default service from getServices()
        $this->assertTrue($locator->has('iterator'));
        // service passed to the constructor
        $this->assertTrue($locator->has('extra'));
    }

    public function testSupportAbstractLocatorGetClassThrowsWhenMissing(): void
    {
        $locator = $this->getLocator(new Di());

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Service missing is not registered');
        $locator->getClass('missing');
    }

    public function testSupportAbstractLocatorHasAndGetClass(): void
    {
        $locator = $this->getLocator(new Di());

        $this->assertTrue($locator->has('iterator'));
        $this->assertFalse($locator->has('missing'));
        $this->assertSame(ArrayIterator::class, $locator->getClass('iterator'));
        $this->assertSame(['iterator' => ArrayIterator::class], $locator->getAll());
    }

    public function testSupportAbstractLocatorNewInstanceResolvesFromContainer(): void
    {
        $container = new Di();
        $container->set(
            ArrayIterator::class,
            function () {
                return new ArrayIterator([]);
            }
        );

        $locator = $this->getLocator($container);

        $this->assertInstanceOf(ArrayIterator::class, $locator->newInstance('iterator'));
    }

    public function testSupportAbstractLocatorNewInstanceThrowsWhenNotInContainer(): void
    {
        $locator = $this->getLocator(new Di());

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('was not found in the DI container');
        $locator->newInstance('iterator');
    }

    public function testSupportAbstractLocatorRegisterAddsService(): void
    {
        $locator = $this->getLocator(new Di());
        $locator->register('another', ArrayIterator::class);

        $this->assertTrue($locator->has('another'));
        $this->assertSame(ArrayIterator::class, $locator->getClass('another'));
    }

    public function testSupportAbstractLocatorRegisterValidatesInterface(): void
    {
        $locator = $this->getLocator(new Di());

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('must implement');
        $locator->register('bad', stdClass::class);
    }

    private function getLocator(Di $container, array $services = []): AbstractLocator
    {
        return new class ($container, $services) extends AbstractLocator {
            protected function getExceptionClass(): string
            {
                return Exception::class;
            }

            protected function getInterfaceClass(): string
            {
                return Countable::class;
            }

            protected function getServices(): array
            {
                return ['iterator' => ArrayIterator::class];
            }
        };
    }
}
