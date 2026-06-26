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

namespace Phalcon\Tests\Unit\Di\Injectable;

use Phalcon\Di\Di;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Di\InjectableComponent;
use Phalcon\Tests\Support\Di\InjectableComponentProtected;
use stdClass;

use function spl_object_hash;

final class UnderscoreGetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiInjectableUnderscoreGetException(): void
    {
        Di::reset();
        $container = new Di();

        $container->set('component', InjectableComponent::class);

        $component = $container->get('component');

        $expected = 'Access to undefined property unknown';
        $actual   = '';
        set_error_handler(
            function (int $errno, string $errstr) use (&$actual): bool {
                $actual = $errstr;

                return true;
            },
            E_USER_NOTICE
        );
        $result = $component->unknown;
        restore_error_handler();
        $this->assertStringContainsString($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiInjectableUnderscoreGetIsset(): void
    {
        Di::reset();
        $container = new Di();

        $stdClass = function () {
            return new stdClass();
        };

        $container->set('std', $stdClass);
        $container->set('component', InjectableComponent::class);

        $component = $container->get('component');
        $actual    = $component->getDI();
        $this->assertSame($container, $actual);

        $class  = stdClass::class;
        $actual = $component->std;
        $this->assertInstanceOf($class, $actual);

        $expected = spl_object_hash($container);
        $actual   = spl_object_hash($component->di);
        $this->assertSame($expected, $actual);

        $actual = isset($component->di);
        $this->assertTrue($actual);

        $actual = isset($component->component);
        $this->assertTrue($actual);

        $actual = isset($component->std);
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiInjectableUnderscoreGetPersistent(): void
    {
        Di::reset();
        $container = new Di();

        // Register sessionBag as a closure that receives the class name
        $container->set(
            'sessionBag',
            function (string $name): stdClass {
                $obj       = new stdClass();
                $obj->name = $name;

                return $obj;
            }
        );

        $container->set('component', InjectableComponent::class);

        /** @var InjectableComponent $component */
        $component  = $container->get('component');
        $persistent = $component->persistent;

        $class = stdClass::class;
        $this->assertInstanceOf($class, $persistent);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17052
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-04
     */
    public function testDiInjectableUnderscoreGetPopulatesDeclaredProperty(): void
    {
        Di::reset();
        $container = new Di();

        $container->setShared(
            'widget',
            function (): stdClass {
                return new stdClass();
            }
        );

        $container->set('component', InjectableComponentProtected::class);

        /** @var InjectableComponentProtected $component */
        $component = $container->get('component');

        // The declared protected property starts unpopulated
        $this->assertNull($component->getWidgetRaw());

        // Magic access resolves the service and, because the property is
        // declared on the class, caches it on the object
        $widget = $component->widget;
        $this->assertInstanceOf(stdClass::class, $widget);

        // The declared property now holds the resolved instance
        $this->assertSame($widget, $component->getWidgetRaw());
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17052
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-04
     */
    public function testDiInjectableUnderscoreGetReflectsReplacedService(): void
    {
        Di::reset();
        $container = new Di();

        $container->setShared(
            'someService',
            function (): stdClass {
                return new stdClass();
            }
        );

        $container->set('component', InjectableComponent::class);

        /** @var InjectableComponent $component */
        $component = $container->get('component');

        // First magic access resolves through the container
        $first = $component->someService;
        $this->assertSame($container->getShared('someService'), $first);

        // Replace the service in the container after the first access
        $container->remove('someService');
        $container->setShared(
            'someService',
            function (): stdClass {
                return new stdClass();
            }
        );

        // The magic property must reflect the replacement, not a stale instance
        $second = $component->someService;
        $this->assertNotSame($first, $second);
        $this->assertSame($container->getShared('someService'), $second);
    }
}
