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

namespace Phalcon\Test\Unit\Http\Message\Uri;

use Phalcon\Http\Message\Uri;
use UnitTester;

class GetPathCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: getPath()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageUriGetPath(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - getPath()');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $expected = '/action';
        $actual   = $uri->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: getPath() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-07
     */
    public function httpUriGetPathEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getPath() - empty');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080';
        $uri   = new Uri($query);

        $actual = $uri->getPath();
        $I->assertEmpty($actual);
    }
}
