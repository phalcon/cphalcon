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
 * Class GetQueryParamsCest
 */
class GetQueryParamsCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getQueryParams()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetQueryParams(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getQueryParams()');
        $I->skipTest('Need implementation');
    }
}
