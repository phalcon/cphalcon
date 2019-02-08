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

use UnitTester;

/**
 * Class GetCookieParamsCest
 */
class GetCookieParamsCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getCookieParams()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpMessageServerRequestGetCookieParams(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getCookieParams()');
        $I->skipTest('Need implementation');
    }
}
