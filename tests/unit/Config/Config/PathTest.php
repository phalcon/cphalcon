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

namespace Phalcon\Tests\Unit\Config\Config;

use Phalcon\Config\Config;
use Phalcon\Tests\AbstractUnitTestCase;

use function uniqid;

final class PathTest extends AbstractUnitTestCase
{
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
