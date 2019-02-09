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

namespace Phalcon\Test\Unit\Http\Message\ResponseFactory;

use UnitTester;

/**
 * Class CreateResponseCest
 */
class CreateResponseCest
{
    /**
     * Tests Phalcon\Http\Message\ResponseFactory :: createResponse()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-09
     */
    public function httpMessageResponseFactoryCreateResponse(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ResponseFactory - createResponse()');
        $I->skipTest('Need implementation');
    }
}
