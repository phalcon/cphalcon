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
}
