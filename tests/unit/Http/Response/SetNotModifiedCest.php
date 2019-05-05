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

use Phalcon\Http\Response;
use UnitTester;

class SetNotModifiedCest
{
    /**
     * Tests Phalcon\Http\Response :: setNotModified()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function httpResponseSetNotModified(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setNotModified()');

        $response = new Response();

        $response->setNotModified();

        $I->assertEquals(
            304,
            $response->getStatusCode()
        );

        $I->assertEquals(
            "Not modified",
            $response->getReasonPhrase()
        );
    }
}
