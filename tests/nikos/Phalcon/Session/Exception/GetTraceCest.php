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

class GetTraceCest
{
    /**
     * Tests Phalcon\Session\Exception :: getTrace()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionExceptionGetTrace(UnitTester $I)
    {
        $I->wantToTest('Session\Exception - getTrace()');

        $I->skipTest('Need implementation');
    }
}
