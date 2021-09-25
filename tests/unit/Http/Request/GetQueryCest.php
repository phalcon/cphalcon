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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Http\Request;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class GetQueryCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Request :: getQuery()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function httpRequestGetQuery(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getQuery()');

        $this->setNewFactoryDefault();

        $store = $_GET ?? [];

        $_GET['status'] = ' Active ';
        $request        = new Request();

        $I->assertTrue($request->hasQuery('status'));
        $I->assertFalse($request->hasQuery('unknown'));

        $expected = ' Active ';
        $actual   = $request->getQuery('status');
        $I->assertEquals($expected, $actual);

        $_GET = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getQuery() - filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function httpRequestGetQueryFilter(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getQuery() - filter');

        $this->setNewFactoryDefault();

        $store = $_GET ?? [];

        $_GET['status'] = ' Active ';
        $request        = new Request();
        $request->setDI($this->container);

        $expected = 'Active';
        $actual   = $request->getQuery('status', 'trim');
        $I->assertEquals($expected, $actual);

        $expected = 'active';
        $actual   = $request->getQuery('status', ['trim', 'lower']);
        $I->assertEquals($expected, $actual);

        $_GET = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getQuery() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function httpRequestGetQueryDefault(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getQuery() - default');

        $this->setNewFactoryDefault();

        $store = $_GET ?? [];

        $request = new Request();
        $request->setDI($this->container);

        $expected = 'default';
        $actual   = $request->getQuery('status', null, 'default');
        $I->assertEquals($expected, $actual);

        $_GET = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getQuery() - allowNoEmpty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function httpRequestGetQueryAllowNoEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getQuery() - allowNoEmpty');

        $this->setNewFactoryDefault();

        $store = $_GET ?? [];

        $_GET['status'] = ' 0 ';
        $request        = new Request();
        $request->setDI($this->container);

        $expected = '0';
        $actual   = $request->getQuery('status', 'trim', 'zero value', true);
        $I->assertEquals($expected, $actual);

        $_GET = $store;
    }
}
