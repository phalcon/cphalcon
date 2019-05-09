<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class IsUpperCest
{
    /**
     * Tests Phalcon\Helper\Str :: isUpper()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrIsUpper(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - isUpper()');

        $actual = Str::isUpper('PHALCON FRAMEWORK');
        $I->assertTrue($actual);

        $actual = Str::isUpper('Phalcon Framework');
        $I->assertFalse($actual);
    }
}
