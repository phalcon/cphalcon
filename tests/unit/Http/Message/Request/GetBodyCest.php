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

namespace Phalcon\Test\Unit\Http\Message\Request;

use UnitTester;

/**
 * Class GetBodyCest
 */
class GetBodyCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getBody()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-09
     */
    public function httpMessageRequestGetBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getBody()');
        $I->skipTest('Need implementation');
    }
}
