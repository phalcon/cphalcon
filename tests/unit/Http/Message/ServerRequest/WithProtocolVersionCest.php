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
 * Class WithProtocolVersionCest
 */
class WithProtocolVersionCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withProtocolVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpMessageServerrequestWithProtocolVersion(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withProtocolVersion()');
        $I->skipTest('Need implementation');
    }
}
