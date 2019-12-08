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
use Phalcon\Http\Cookie;
use UnitTester;

class GetSetCookiesCest
{
    /**
     * Tests Phalcon\Http\Response :: getCookies() / setCookies()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseGetSetCookies(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getCookies() / setCookies');

        $oCookie = new Cookie('firstname','jeremy');
        
        $oResponse = new Response();
        $oResponse->setCookies($oCookie);

        $I->assertSame(
            $oCookie, 
            $oResponse->getCookies()
        );
    }
}
