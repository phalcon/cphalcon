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

namespace Phalcon\Test\Unit\Debug\Exception;

use UnitTester;

/**
 * Class GetLineCest
 */
class GetLineCest
{
    /**
     * Tests Phalcon\Debug\Exception :: getLine()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function debugExceptionGetLine(UnitTester $I)
    {
        $I->wantToTest('Debug\Exception - getLine()');
        $I->skipTest('Need implementation');
    }
}
