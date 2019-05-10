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

use Phalcon\Http\Message\Response;
use UnitTester;

class GetHeaderLineCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getHeaderLine()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetHeaderLine(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getHeaderLine()');

        $data = [
            'Accept' => [
                'text/html',
                'text/json',
            ],
        ];

        $request = new Response('php://memory', 200, $data);

        $expected = 'text/html,text/json';

        $I->assertEquals(
            $expected,
            $request->getHeaderLine('accept')
        );

        $I->assertEquals(
            $expected,
            $request->getHeaderLine('aCCepT')
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getHeaderLine() - empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetHeaderLineEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getHeaderLine() - empty');

        $request = new Response();

        $I->assertEquals(
            '',
            $request->getHeaderLine('accept')
        );
    }
}
