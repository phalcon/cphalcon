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

namespace Phalcon\Test\Unit\Http\Cookie\Exception;

use UnitTester;

/**
 * Class GetPreviousCest
 */
class GetPreviousCest
{
    /**
     * Tests Phalcon\Http\Cookie\Exception :: getPrevious()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpCookieExceptionGetPrevious(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie\Exception - getPrevious()');
        $I->skipTest('Need implementation');
    }
}
