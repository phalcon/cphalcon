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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\IsLower;
use UnitTester;

/**
 * Class IsLowerCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class IsLowerCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: isLower()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrIsLower(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - isLower()');

        $object = new IsLower();
        $actual = $object('phalcon framework');
        $I->assertTrue($actual);

        $actual = $object('Phalcon Framework');
        $I->assertFalse($actual);
    }
}
