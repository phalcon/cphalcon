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

use Phalcon\Support\Helper\Str\Prefix;
use UnitTester;

/**
 * Class PrefixCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class PrefixCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: prefix()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrPrefix(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - prefix()');

        $object = new Prefix();

        $expected = 'ClassConstants';
        $actual   = $object('Constants', 'Class');
        $I->assertEquals($expected, $actual);
    }
}
