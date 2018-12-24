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

namespace Phalcon\Test\Unit\Http\Request;

use UnitTester;

/**
 * Class IsOptionsCest
 */
class IsOptionsCest
{
    /**
     * Tests Phalcon\Http\Request :: isOptions()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestIsOptions(UnitTester $I)
    {
        $I->wantToTest('Http\Request - isOptions()');
        $I->skipTest('Need implementation');
    }
}
