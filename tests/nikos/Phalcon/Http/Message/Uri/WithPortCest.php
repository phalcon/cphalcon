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

namespace Phalcon\Test\Unit\Http\Message\Uri;

use UnitTester;

/**
 * Class WithPortCest
 */
class WithPortCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withPort()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUriWithPort(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - withPort()');
        $I->skipTest('Need implementation');
    }
}
