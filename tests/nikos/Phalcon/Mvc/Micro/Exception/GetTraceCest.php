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

namespace Phalcon\Test\Unit\Mvc\Micro\Exception;

use UnitTester;

class GetTraceCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Exception :: getTrace()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function mvcMicroExceptionGetTrace(UnitTester $I)
    {
        $I->wantToTest('Mvc\Micro\Exception - getTrace()');

        $I->skipTest('Need implementation');
    }
}
