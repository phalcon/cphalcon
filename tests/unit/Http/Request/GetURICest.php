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
 * Class GetURICest
 */
class GetURICest
{
    /**
     * Tests Phalcon\Http\Request :: getURI()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestGetURI(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getURI()');
        $I->skipTest('Need implementation');
    }
}
