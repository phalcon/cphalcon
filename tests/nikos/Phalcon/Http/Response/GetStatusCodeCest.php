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

namespace Phalcon\Test\Unit\Http\Response;

use UnitTester;

class GetStatusCodeCest
{
    /**
     * Tests Phalcon\Http\Response :: getStatusCode()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpResponseGetStatusCode(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getStatusCode()');

        $I->skipTest('Need implementation');
    }
}
