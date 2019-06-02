<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetHeaderLineCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getHeaderLine()
     *
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
