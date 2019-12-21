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

namespace Phalcon\Test\Unit\Http\Response;

use DateTime;
use DateTimeZone;
use Phalcon\Http\Response;
use UnitTester;

class SetLastModifiedCest
{
    /**
     * Tests Phalcon\Http\Response :: setLastModified()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseSetLastModified(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setLastModified()');

        $oResponse = new Response('<h1>Phalcon</h1>');

        $oLastModified = new DateTime();

        $oLastModified->modify('+1 months');

        $oLastModified->setTimezone(
            new DateTimeZone("UTC")
        );

        $oResponse->setLastModified($oLastModified);

        $I->assertSame(
            $oLastModified->format("D, d M Y H:i:s") . " GMT",
            $oResponse->getHeaders()->get('Last-Modified')
        );
    }
}
