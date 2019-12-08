<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Http\Response;
use UnitTester;

class GetSetStatusCodeCest
{
    /**
     * Tests Phalcon\Http\Response :: getStatusCode() / setStatusCode()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseGetSetStatusCode(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getStatusCode() / setStatusCode()');

        $nCode = 200;

        $oResponse = new Response();
        $oResponse->setStatusCode($nCode);
        
        $I->assertSame(
            $nCode,
            $oResponse->getStatusCode()
        );
    }
}
