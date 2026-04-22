<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Definition;

use Exception;
use Phalcon\Container\Definition\DefinitionType;
use Phalcon\Container\Definition\ServiceDefinition;
use Phalcon\Container\Definition\ServiceLifetime;
use Phalcon\Container\Exception\Invalid;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Definition\Fake\FakeServiceWithResolve;
use Phalcon\Tests\Unit\Container\Fake\FakeContainer;
use stdClass;

final class ServiceDefinitionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionAddGetExtenders(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $this->assertFalse($def->hasExtenders());

        $extender = static function (object $instance, object $c) {
            return $instance;
        };
        $def->addExtender($extender);

        $this->assertTrue($def->hasExtenders());
        $this->assertCount(1, $def->getExtenders());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionAddTag(): void
    {
        $def = new ServiceDefinition('mailer', DefinitionType::STRING);
        $def->addTag('notifier');
        $this->assertContains('notifier', $def->getTags());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionAddTagDeduplicated(): void
    {
        $def = new ServiceDefinition('mailer', DefinitionType::STRING);
        $def->addTag('notifier');
        $def->addTag('notifier');
        $this->assertCount(1, $def->getTags());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionBuildServiceResolvesLazyArg(): void
    {
        $lazy      = new FakeServiceWithResolve();
        $container = new FakeContainer();
        $def       = new ServiceDefinition(Exception::class, DefinitionType::STRING);
        $def->setClass(Exception::class);
        $this->setProtectedProperty($def, 'constructorArgs', [$lazy]);
        $def->freeze($container);

        $instance = $def->buildService($container);
        $this->assertInstanceOf(Exception::class, $instance);
        $this->assertSame('lazy message', $instance->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionDefaultLifetimeIsScoped(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $this->assertSame(ServiceLifetime::SCOPED, $def->getLifetime());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionFreezeIsIdempotent(): void
    {
        $container = new FakeContainer();
        $def       = new ServiceDefinition('logger', DefinitionType::CLOSURE);
        $def->freeze($container);
        $def->freeze($container);
        $this->assertTrue($def->isFrozen());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionFreezeWithExplicitArgsNoAutowire(): void
    {
        $container = new FakeContainer();
        $def       = new ServiceDefinition('svc', DefinitionType::STRING);
        $def->setClass(stdClass::class);
        $def->setArgument(0, 'value');
        $def->freeze($container);

        $this->assertSame(['value'], $def->getConstructorArgs());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionGetClassThrowsWhenNotSet(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $this->expectException(Invalid::class);
        $def->getClass();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionGetConstructorArgsEmpty(): void
    {
        $container = new FakeContainer();
        $def       = new ServiceDefinition('svc', DefinitionType::CLOSURE);
        $def->freeze($container);

        $this->assertSame([], $def->getConstructorArgs());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionGetFactoryThrowsWhenNotSet(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $this->expectException(Invalid::class);
        $def->getFactory();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionGetServiceName(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $this->assertSame('logger', $def->getServiceName());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionGetType(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $this->assertSame(DefinitionType::STRING, $def->getType());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionIsCacheableFalseByDefault(): void
    {
        $container = new FakeContainer();
        $def       = new ServiceDefinition('logger', DefinitionType::CLOSURE);
        $def->freeze($container);
        $this->assertFalse($def->isCacheable());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionIsCacheableOnlyWhenFrozenAndFlagSet(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $def->setIsCacheable(true);
        $this->assertFalse($def->isCacheable());

        $container = new FakeContainer();
        $def->freeze($container);
        $this->assertTrue($def->isCacheable());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionIsNotFrozenInitially(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $this->assertFalse($def->isFrozen());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionSetArgument(): void
    {
        $def = new ServiceDefinition('db', DefinitionType::STRING);
        $def->setArgument('host', 'localhost');
        $this->assertSame(['host' => 'localhost'], $def->getArguments());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionSetExtendersReplacesAll(): void
    {
        $def       = new ServiceDefinition('logger', DefinitionType::STRING);
        $extenderA = static function (object $o, object $c) {
            return $o;
        };
        $extenderB = static function (object $o, object $c) {
            return $o;
        };

        $def->addExtender($extenderA);
        $def->setExtenders([$extenderB]);

        $this->assertCount(1, $def->getExtenders());
        $this->assertSame($extenderB, $def->getExtenders()[0]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionSetGetClass(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $def->setClass('SomeClass');
        $this->assertTrue($def->hasClass());
        $this->assertSame('SomeClass', $def->getClass());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionSetGetFactory(): void
    {
        $factory = static function () {
            return new stdClass();
        };
        $def = new ServiceDefinition('logger', DefinitionType::CLOSURE);
        $def->setFactory($factory);
        $this->assertTrue($def->hasFactory());
        $this->assertSame($factory, $def->getFactory());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionSetGetLifetime(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $def->setLifetime(ServiceLifetime::SINGLETON);
        $this->assertSame(ServiceLifetime::SINGLETON, $def->getLifetime());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionSetterThrowsWhenFrozen(): void
    {
        $container = new FakeContainer();
        $def       = new ServiceDefinition('logger', DefinitionType::CLOSURE);
        $def->freeze($container);

        $this->expectException(Invalid::class);
        $def->setLifetime(ServiceLifetime::SINGLETON);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionUnsetClass(): void
    {
        $def = new ServiceDefinition('logger', DefinitionType::STRING);
        $def->setClass('SomeClass');
        $def->unsetClass();
        $this->assertFalse($def->hasClass());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionUnsetExtenders(): void
    {
        $def      = new ServiceDefinition('logger', DefinitionType::STRING);
        $extender = static function (object $o, object $c) {
            return $o;
        };
        $def->addExtender($extender);
        $def->unsetExtenders();
        $this->assertFalse($def->hasExtenders());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionServiceDefinitionUnsetFactory(): void
    {
        $factory = static function () {
            return new stdClass();
        };
        $def = new ServiceDefinition('logger', DefinitionType::CLOSURE);
        $def->setFactory($factory);
        $def->unsetFactory();
        $this->assertFalse($def->hasFactory());
    }
}
