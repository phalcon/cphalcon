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

namespace Phalcon\Test\Unit\Http\Message\Response;

use UnitTester;

/**
 * Class WithBodyCest
 */
class WithBodyCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: withBody()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-09
     */
    public function httpMessageResponseWithBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withBody()');
        $I->skipTest('Need implementation');
    }
}
