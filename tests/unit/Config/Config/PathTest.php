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

namespace Phalcon\Tests\Unit\Config\Config;

use Phalcon\Config\Config;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

use function uniqid;

final class PathTest extends AbstractUnitTestCase
{
    /**
     * A path with keys calls has() only for the full path, not for each key.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17714
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-02
     */
    public function testConfigPathCallsHasForFullPathOnly(): void
    {
        $config = new class (['a' => ['b' => 'x']]) extends Config {
            public static int $hasCalls = 0;

            public function has(string $element): bool
            {
                self::$hasCalls++;

                return parent::has($element);
            }
        };

        $this->assertSame('x', $config->path('a.b'));
        $this->assertSame(1, $config::$hasCalls);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testConfigPathEmptyValueReturnsDefault(): void
    {
        $config = new Config(['a' => '']);
        $actual = $config->path('a.b', 'default');

        $this->assertSame('default', $actual);
    }

    /**
     * A falsy value at the last key gives the value, not the default.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17714
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-02
     */
    public function testConfigPathFalsyValueReturnsValue(): void
    {
        $config = new Config(['a' => ['b' => 0]]);

        $this->assertSame(0, $config->path('a.b', 'default'));
    }

    /**
     * A null value at the last key gives null, not the default.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17714
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-02
     */
    public function testConfigPathNullValueReturnsNull(): void
    {
        $config = new Config(['a' => ['b' => null]]);

        $this->assertNull($config->path('a.b', 'default'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testConfigPathSkippedMissingKeyReturnsDefault(): void
    {
        $deepValue = uniqid('value-');
        $config    = new Config(
            [
                'a' => [
                    'b' => $deepValue,
                ],
            ]
        );

        /**
         * 'a.x.b' contains a missing middle key 'x'; path() must stop and
         * return the default, not skip 'x' and resolve the deeper 'b'.
         */
        $actual = $config->path('a.x.b', 'default');
        $this->assertSame('default', $actual);
    }
}
