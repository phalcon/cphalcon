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

namespace Phalcon\Test\Unit\Http\Uri;

use Phalcon\Http\Uri;
use UnitTester;

/**
 * Class GetAuthorityCest
 */
class GetAuthorityCest
{
    /**
     * Tests Phalcon\Http\Uri :: getAuthority()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriGetAuthority(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getAuthority()');
        $query = 'https://dev.phalcon.ld';
        $uri   = new Uri($query);

        $expected = 'dev.phalcon.ld';
        $actual   = $uri->getAuthority();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Uri :: getAuthority() - with user info
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriGetAuthorityWithUserInfo(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getAuthority() - with user info');
        $query = 'https://phalcon:secret@dev.phalcon.ld';
        $uri   = new Uri($query);

        $expected = 'phalcon:secret@dev.phalcon.ld';
        $actual   = $uri->getAuthority();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Uri :: getAuthority() - with port
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriGetAuthorityWithPort(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getAuthority() - with port');
        $query = 'https://dev.phalcon.ld:8080';
        $uri   = new Uri($query);

        $expected = 'dev.phalcon.ld:8080';
        $actual   = $uri->getAuthority();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Uri :: getAuthority() - full
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriGetAuthorityFull(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getAuthority() - with user info');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080';
        $uri   = new Uri($query);

        $expected = 'phalcon:secret@dev.phalcon.ld:8080';
        $actual   = $uri->getAuthority();
        $I->assertEquals($expected, $actual);
    }
}
