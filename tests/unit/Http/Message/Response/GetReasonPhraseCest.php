<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

class GetReasonPhraseCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getReasonPhrase()
     *
     * @since  2019-03-09
     */
    public function httpMessageResponseGetReasonPhrase(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getReasonPhrase()');

        $response = new Response();

        $I->assertEquals(
            'OK',
            $response->getReasonPhrase()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getReasonPhrase() - other port
     *
     * @since  2019-03-09
     */
    public function httpMessageResponseGetReasonPhraseOtherPort(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getReasonPhrase() - other port');

        $response = new Response('php://memory', 420);

        $I->assertEquals(
            'Method Failure',
            $response->getReasonPhrase()
        );
    }
}
