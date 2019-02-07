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

namespace Phalcon\Test\Unit\Http\Uri;

use UnitTester;

/**
 * Class WithUserInfoCest
 */
class WithUserInfoCest
{
    /**
     * Tests Phalcon\Http\Uri :: withUserInfo()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriWithUserInfo(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - withUserInfo()');
        $I->skipTest('Need implementation');
    }
}
