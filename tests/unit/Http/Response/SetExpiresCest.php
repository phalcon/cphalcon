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
use DateTime;
use DateTimeZone;
use UnitTester;

class SetExpiresCest
{
    /**
     * Tests Phalcon\Http\Response :: setExpires()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
    */
    public function httpResponseSetExpires(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setExpires()');

        $oResponse = new Response('<h1>Phalcon</h1>');

        $oExpireDate = new DateTime();

        $oExpireDate->modify('+1 months');

        $oExpireDate->setTimezone(
            new DateTimeZone("UTC")
        );
        
        $oResponse->setExpires($oExpireDate);

        $I->assertSame(
            $oExpireDate->format("D, d M Y H:i:s") . " GMT", 
            $oResponse->getHeaders()->get('Expires')
        );
    }
}
