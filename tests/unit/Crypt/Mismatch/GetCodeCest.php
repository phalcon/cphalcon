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
 * Class GetCodeCest
 */
class GetCodeCest
{
    /**
     * Tests Phalcon\Crypt\Mismatch :: getCode()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-16
     */
    public function cryptMismatchGetCode(UnitTester $I)
    {
        $I->wantToTest('Crypt\Mismatch - getCode()');

        $I->skipTest('Need implementation');
    }
}
