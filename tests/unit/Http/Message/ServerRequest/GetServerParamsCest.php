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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

/**
 * Class GetServerParamsCest
 */
class GetServerParamsCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getServerParams()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetServerParams(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getServerParams()');
        $params  = ['one' => 'two'];
        $request = new ServerRequest('GET', null, $params);

        $expected = $params;
        $actual   = $request->getServerParams();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getServerParams() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetServerParamsEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getServerParams() - empty');
        $request = new ServerRequest();

        $actual = $request->getServerParams();
        $I->assertEmpty($actual);
    }
}
