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

class IsSentCest
{
    /**
     * Tests Phalcon\Http\Response :: isSent()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
    */
    public function httpResponseIsSent(UnitTester $I)
    {
        $I->wantToTest('Http\Response - isSent()');

        $sData = '<h1>Phalcon</h1>';
        $oResponse = new Response('<h1>Phalcon</h1>');
       
        ob_start();

        $oResponse->send();
        $sResult   = ob_get_clean();

        $I->assertEquals($sData, $sResult);

        $I->assertTrue($oResponse->isSent());
    }
}
