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

        $this->setNewFactoryDefault();

        $existing = $_POST ?? [];

        $_POST['status'] = ' Active ';
        $request         = new Request();

        $expected = ' Active ';
        $actual   = $request->getPost('status');
        $I->assertEquals($expected, $actual);

        $_POST = $existing;
    }

    /**
     * Tests Phalcon\Http\Request :: getPost() - filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function httpRequestGetPostFilter(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost() - filter');

        $this->setNewFactoryDefault();

        $existing = $_POST ?? [];

        $_POST['status'] = ' Active ';
        $request         = new Request();
        $request->setDI($this->container);

        $expected = 'Active';
        $actual   = $request->getPost('status', 'trim');
        $I->assertEquals($expected, $actual);

        $expected = 'active';
        $actual   = $request->getPost('status', ['trim', 'lower']);
        $I->assertEquals($expected, $actual);

        $_POST = $existing;
    }

    /**
     * Tests Phalcon\Http\Request :: getPost() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function httpRequestGetPostDefault(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost() - default');

        $this->setNewFactoryDefault();

        $existing = $_POST ?? [];

        $request = new Request();
        $request->setDI($this->container);

        $expected = 'default';
        $actual   = $request->getPost('status', null, 'default');
        $I->assertEquals($expected, $actual);

        $_POST = $existing;
    }

    /**
     * Tests Phalcon\Http\Request :: getPost() - allowNoEmpty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function httpRequestGetPostAllowNoEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPost() - allowNoEmpty');

        $this->setNewFactoryDefault();

        $existing = $_POST ?? [];

        $_POST['status'] = ' 0 ';
        $request         = new Request();
        $request->setDI($this->container);

        $expected = '0';
        $actual   = $request->getPost('status', 'trim', 'zero value', true);
        $I->assertEquals($expected, $actual);

        $_POST = $existing;
    }
}
