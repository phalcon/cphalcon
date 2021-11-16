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

namespace Phalcon\Tests\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetHeaderLineCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getHeaderLine()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetHeaderLine(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getHeaderLine()');
        $data    = [
            'Accept' => [
                'text/html',
                'text/json',
            ],
        ];
        $request = new ServerRequest('GET', null, [], 'php://input', $data);

        $expected = 'text/html,text/json';
        $actual   = $request->getHeaderLine('accept');
        $I->assertEquals($expected, $actual);

        $actual = $request->getHeaderLine('aCCepT');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getHeaderLine() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetHeaderLineEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getHeaderLine() - empty');
        $request = new ServerRequest();

        $expected = '';
        $actual   = $request->getHeaderLine('accept');
        $I->assertEquals($expected, $actual);
    }
}
