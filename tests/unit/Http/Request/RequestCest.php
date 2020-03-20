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

namespace Phalcon\Test\Unit\Http;

use Codeception\Example;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class RequestCest extends HttpBase
{
    /**
     * Tests POST functions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputPost(UnitTester $I)
    {
        $this->hasEmpty($I, 'hasPost');
        $this->hasNotEmpty($I, 'hasPost', 'setPostVar');

        $this->getEmpty($I, 'getPost');
        $this->getNotEmpty($I, 'getPost', 'setPostVar');

        $this->getSanitized($I, 'getPost', 'setPostVar');

        $this->getSanitizedArrayFilter($I, 'getPost', ['string'], 'setPostVar');
    }

    /**
     * Tests GET functions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputGet(UnitTester $I)
    {
        $this->hasEmpty($I, 'hasQuery');
        $this->hasNotEmpty($I, 'hasQuery', 'setGetVar');

        $this->getEmpty($I, 'getQuery');
        $this->getNotEmpty($I, 'getQuery', 'setGetVar');

        $this->getSanitized($I, 'getQuery', 'setGetVar');

        $this->getSanitizedArrayFilter($I, 'getQuery', ['string'], 'setGetVar');
    }

    /**
     * Tests REQUEST functions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputRequest(UnitTester $I)
    {
        $this->hasEmpty($I, 'has');
        $this->hasNotEmpty($I, 'has', 'setRequestVar');

        $this->getEmpty($I, 'get');
        $this->getNotEmpty($I, 'get', 'setRequestVar');

        $this->getSanitized($I, 'get', 'setRequestVar');

        $this->getSanitizedArrayFilter($I, 'get', ['string'], 'setRequestVar');
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1265
     */
    public function testRequestGetValueByUsingSeveralMethods(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_REQUEST = $_GET = $_POST = [
            'string' => 'hello',
            'array'  => ['string' => 'world'],
        ];

        // get
        $I->assertEquals('hello', $request->get('string', 'string'));
        $I->assertEquals('hello', $request->get('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->get('array', 'string'));
        $I->assertEquals(null, $request->get('array', 'string', null, true, true));

        // getQuery
        $I->assertEquals('hello', $request->getQuery('string', 'string'));
        $I->assertEquals('hello', $request->getQuery('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->getQuery('array', 'string'));
        $I->assertEquals(null, $request->getQuery('array', 'string', null, true, true));

        // getPost
        $I->assertEquals('hello', $request->getPost('string', 'string'));
        $I->assertEquals('hello', $request->getPost('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->getPost('array', 'string'));
        $I->assertEquals(null, $request->getPost('array', 'string', null, true, true));
    }

    public function testRequestGetQuery(UnitTester $I)
    {
        $_REQUEST = $_GET = $_POST = [
            'id'    => 1,
            'num'   => 'a1a',
            'age'   => 'aa',
            'phone' => '',
        ];

        $functions = ['get', 'getQuery', 'getPost'];

        foreach ($functions as $function) {
            $request = $this->getRequestObject();

            $I->assertEquals(
                1,
                $request->$function('id', 'int', 100)
            );

            $I->assertEquals(
                1,
                $request->$function('num', 'int', 100)
            );

            $I->assertEmpty(
                $request->$function('age', 'int', 100)
            );

            $I->assertEmpty(
                $request->$function('phone', 'int', 100)
            );

            $I->assertEquals(
                100,
                $request->$function('phone', 'int', 100, true)
            );
        }
    }
}
