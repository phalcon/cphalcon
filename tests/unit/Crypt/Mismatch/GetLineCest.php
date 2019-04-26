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

namespace Phalcon\Test\Unit\Crypt\Mismatch;

use UnitTester;

/**
 * Class GetLineCest
 */
class GetLineCest
{
    /**
     * Tests Phalcon\Crypt\Mismatch :: getLine()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-16
     */
    public function cryptMismatchGetLine(UnitTester $I)
    {
        $I->wantToTest('Crypt\Mismatch - getLine()');

        $I->skipTest('Need implementation');
    }
}
