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
use Phalcon\Tests\Support\Traits\ConfigTrait;

final class OffsetGetTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @author Rian Orie <rian.orie@gmail.com>
     * @since  2014-11-12
     */
    public function testNumericConfig(): void
    {
        $config = new Config(
            [
                'abc',
            ]
        );

        $expected = 'abc';
        $actual   = $config->{0};
        $this->assertSame($expected, $actual);
    }
}
