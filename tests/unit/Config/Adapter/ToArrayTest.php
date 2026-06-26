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
use PHPUnit\Framework\Attributes\DataProvider;

final class ToArrayTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @return array[]
     */
    public static function providerAdapters(): array
    {
        return [
            [''],
            ['Json'],
            ['Php'],
            ['Yaml'],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[DataProvider('providerAdapters')]
    public function testConfigAdapterToArray(string $adapter): void
    {
        $config = $this->getConfig($adapter);

        $expected = $this->config;
        $actual   = $config->toArray();
        $this->assertEquals($expected, $actual);
    }
}
