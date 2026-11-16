<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;

/**
 * The container creates the services and injects the values with the PHP
 * weak type rules, the same as cphalcon. The test file declares
 * strict_types=1, so the mode of the caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    private const PARAMETER = [
        'type'  => 'parameter',
        'value' => '5',
    ];

    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testDiWeakModeDefinitionArguments(): void
    {
        $container = new Di();
        $container->set(
            't',
            [
                'className' => IntTarget::class,
                'arguments' => [self::PARAMETER],
            ]
        );

        $this->assertSame(5, $container->get('t')->value);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testDiWeakModeDefinitionCalls(): void
    {
        $container = new Di();
        $container->set(
            't',
            [
                'className' => IntTarget::class,
                'calls'     => [
                    [
                        'method'    => 'setValue',
                        'arguments' => [self::PARAMETER],
                    ],
                ],
            ]
        );

        $this->assertSame(5, $container->get('t')->value);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testDiWeakModeDefinitionGetParameters(): void
    {
        $container = new Di();
        $container->set('t', ['className' => IntTarget::class]);

        $this->assertSame(5, $container->get('t', ['5'])->value);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testDiWeakModeDefinitionProperties(): void
    {
        $container = new Di();
        $container->set(
            't',
            [
                'className'  => IntTarget::class,
                'properties' => [
                    [
                        'name'  => 'value',
                        'value' => self::PARAMETER,
                    ],
                ],
            ]
        );

        $this->assertSame(5, $container->get('t')->value);
    }

    /**
     * The class is not registered. The container creates it.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testDiWeakModeGetParameters(): void
    {
        $container = new Di();

        $this->assertSame(5, $container->get(IntTarget::class, ['5'])->value);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testDiWeakModeServiceClosureParameters(): void
    {
        $container = new Di();
        $container->set(
            't',
            function (int $value): IntTarget {
                return new IntTarget($value);
            }
        );

        $this->assertSame(5, $container->get('t', ['5'])->value);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testDiWeakModeServiceParameters(): void
    {
        $container = new Di();
        $container->set('t', IntTarget::class);

        $this->assertSame(5, $container->get('t', ['5'])->value);
    }
}
