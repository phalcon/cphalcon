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

namespace Phalcon\Tests\Unit\Http\Message\Uri;

use Phalcon\Http\Message\Uri;
use UnitTester;

class GetUserInfoCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: getUserInfo()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageUriGetUserInfo(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - getUserInfo()');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $expected = 'phalcon:secret';
        $actual   = $uri->getUserInfo();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: getUserInfo() - only user
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-07
     */
    public function httpUriGetUserInfoOnlyUser(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getUserInfo() - only user');
        $query = 'https://phalcon@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $expected = 'phalcon';
        $actual   = $uri->getUserInfo();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: getUserInfo() - only pass
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-07
     */
    public function httpUriGetUserInfoOnlyPass(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getUserInfo() - only pass');
        $query = 'https://:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $expected = ':secret';
        $actual   = $uri->getUserInfo();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: getUserInfo() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-07
     */
    public function httpUriGetUserInfoEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getUserInfo() - empty');
        $query = 'https://dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $actual = $uri->getUserInfo();
        $I->assertEmpty($actual);
    }
}
