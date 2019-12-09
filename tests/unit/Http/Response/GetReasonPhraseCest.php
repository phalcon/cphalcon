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

class GetReasonPhraseCest
{
    /**
     * Tests Phalcon\Http\Response :: getReasonPhrase()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
    */
    public function httpResponseGetReasonPhrase(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getReasonPhrase()');

        $sPhrase = 'Success';
        $oResponse = new Response('<h1>Test</h1>', 200, $sPhrase);

        $I->assertSame(
            $sPhrase,
            $oResponse->getReasonPhrase()
        );
    }
}
