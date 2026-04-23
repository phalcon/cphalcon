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

use Phalcon\Config\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\ConfigTrait;

final class MergeTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @dataProvider providerConfigAdapters
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function testConfigAdapterMergeException(string $adapter): void
    {
        $config = $this->getConfig($adapter);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Invalid data type for merge.');

        $config->merge(false);
    }
}
