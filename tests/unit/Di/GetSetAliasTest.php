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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionProperty;

use function uniqid;

final class GetSetAliasTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-02-17
     */
    public function testDiGetAlias(): void
    {
        $container = new Di();

        /**
         * Alias does not exist
         */
        $name   = uniqid('nam-');
        $actual = $container->getAlias($name);
        $this->assertEmpty($actual);

        // Set the service
        $container->set('escaper', Escaper::class, true);
        $container->setAlias('escaper', EscaperInterface::class);

        $source  = $container->get('escaper');
        $aliased = $container->get(EscaperInterface::class);
        $this->assertSame($source, $aliased);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-02-17
     */
    public function testDiSetAliases(): void
    {
        $container = new Di();

        $aliases = [
            EscaperInterface::class,
            'my_escaper',
        ];

        $container->set('escaper', Escaper::class, true);
        $container->setAlias('escaper', $aliases);

        $source  = $container->get('escaper');
        $aliased = $container->get(EscaperInterface::class);
        $this->assertSame($source, $aliased);

        $aliased = $container->get('my_escaper');
        $this->assertSame($source, $aliased);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiResolveAliasCircular(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Circular alias reference detected while resolving 'a'"
        );

        $container = new Di();

        // Manually inject a circular alias chain: a → b → a
        $prop = new ReflectionProperty(Di::class, 'aliases');
        $prop->setAccessible(true);
        $prop->setValue($container, ['a' => 'b', 'b' => 'a']);

        // Resolving 'a' walks a→b→a→b… and detects the cycle
        $container->get('a');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiSetAliasNotRegistered(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'nonexistent' is not registered in the container"
        );

        $container = new Di();
        $container->setAlias('nonexistent', 'myAlias');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-02-17
     */
    public function testDiSetAliasesExceptionNameNotString(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Alias name must be a string');

        $container = new Di();

        $aliases = [
            123456,
        ];

        $container->set('escaper', Escaper::class, true);
        $container->setAlias('escaper', $aliases);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-02-17
     */
    public function testDiSetAliasesExceptionNameExists(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Alias 'escaper' is already in use by an existing service"
        );

        $container = new Di();

        $aliases = [
            EscaperInterface::class,
            'escaper'
        ];

        $container->set('escaper', Escaper::class, true);
        $container->setAlias('escaper', $aliases);
    }
}
