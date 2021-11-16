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
use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
use UnitTester;

class OffsetGetCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Config :: offsetGet()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function configOffsetGet(UnitTester $I)
    {
        $I->wantToTest('Config\Config - offsetGet()');

        $this->checkOffsetGet($I);
    }

    /**
     * Tests access by numeric key
     *
     * @author Rian Orie <rian.orie@gmail.com>
     * @since  2014-11-12
     */
    public function testNumericConfig(UnitTester $I)
    {
        $config = new Config(
            [
                'abc',
            ]
        );

        $expected = 'abc';
        $actual   = $config->{0};
        $I->assertEquals($expected, $actual);
    }
}
