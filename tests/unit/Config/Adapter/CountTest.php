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

final class CountTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @dataProvider providerConfigAdapters
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testConfigAdapterCount(string $adapter): void
    {
        $config = $this->getConfig($adapter);

        $expected = 5;
        $actual   = $config->count();
        $this->assertEquals($expected, $actual);
    }
}
