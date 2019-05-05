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

namespace Phalcon\Test\Unit\Application\Exception;

use UnitTester;

class GetTraceCest
{
    /**
     * Tests Phalcon\Application\Exception :: getTrace()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function applicationExceptionGetTrace(UnitTester $I)
    {
        $I->wantToTest('Application\Exception - getTrace()');

        $I->skipTest('Need implementation');
    }
}
