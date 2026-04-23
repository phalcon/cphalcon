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

namespace Phalcon\Tests\Unit\Config\Adapter;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\ConfigTrait;

final class PathTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @dataProvider providerConfigAdaptersNotGrouped
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testConfigAdapterPath(string $adapter): void
    {
        $config = $this->getConfig($adapter);

        $expected = 1;
        $actual   = $config->path('test');
        $this->assertCount($expected, $actual);

        $expected = 'yeah';
        $actual   = $config->path('test.parent.property2');
        $this->assertEquals($expected, $actual);
    }

    /**
     * @dataProvider providerConfigAdapters
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testConfigAdapterPathDefault(string $adapter): void
    {
        $config = $this->getConfig($adapter);

        $expected = 'Unknown';
        $actual   = $config->path('test.parent.property3', 'Unknown');
        $this->assertEquals($expected, $actual);
    }
}
