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

namespace Phalcon\Test\Unit\Session\Exception;

use UnitTester;

/**
 * Class GetTraceAsStringCest
 */
class GetTraceAsStringCest
{
    /**
     * Tests Phalcon\Session\Exception :: getTraceAsString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function sessionExceptionGetTraceAsString(UnitTester $I)
    {
        $I->wantToTest('Session\Exception - getTraceAsString()');
        $I->skipTest('Need implementation');
    }
}
