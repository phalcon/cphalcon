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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class GetPostCest //extends HttpBase
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Request :: getPost()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function httpRequestGetPost(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost()');

        $store = $_POST ?? [];
        $_POST = [
            'one' => 'two',
        ];

        $request = new Request();

        $I->assertTrue($request->hasPost('one'));
        $I->assertFalse($request->hasPost('unknown'));
        $I->assertEquals('two', $request->getPost('one'));

        $_POST = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getPost() - filter
     *
     * @throws Exception
     * @since  2019-12-01
     * @author Phalcon Team <team@phalcon.io>
     */
    public function httpRequestGetPostFilter(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost() - filter');

        $this->setNewFactoryDefault();

        $store = $_POST ?? [];

        $_POST['status'] = ' Active ';
        $request         = new Request();
        $request->setDI($this->container);

        $expected = 'Active';
        $actual   = $request->getPost('status', 'trim');
        $I->assertEquals($expected, $actual);

        $expected = 'active';
        $actual   = $request->getPost('status', ['trim', 'lower']);
        $I->assertEquals($expected, $actual);

        $_POST = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getPost() - default
     *
     * @throws Exception
     * @since  2019-12-01
     * @author Phalcon Team <team@phalcon.io>
     */
    public function httpRequestGetPostDefault(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost() - default');

        $this->setNewFactoryDefault();

        $store = $_POST ?? [];

        $request = new Request();
        $request->setDI($this->container);

        $expected = 'default';
        $actual   = $request->getPost('status', null, 'default');
        $I->assertEquals($expected, $actual);

        $_POST = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getPost() - allowNoEmpty
     *
     * @throws Exception
     * @since  2019-12-01
     * @author Phalcon Team <team@phalcon.io>
     */
    public function httpRequestGetPostAllowNoEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost() - allowNoEmpty');

        $this->setNewFactoryDefault();

        $store = $_POST ?? [];

        $_POST['status'] = ' 0 ';
        $request         = new Request();
        $request->setDI($this->container);

        $expected = '0';
        $actual   = $request->getPost('status', 'trim', 'zero value', true);
        $I->assertEquals($expected, $actual);

        $_POST = $store;
    }
}
