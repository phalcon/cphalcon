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
 * Class GetParsedBodyCest
 */
class GetParsedBodyCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getParsedBody()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpMessageServerrequestGetParsedBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getParsedBody()');
        $I->skipTest('Need implementation');
    }
}
