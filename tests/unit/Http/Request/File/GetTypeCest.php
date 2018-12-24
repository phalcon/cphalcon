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

namespace Phalcon\Test\Unit\Http\Request\File;

use UnitTester;

/**
 * Class GetTypeCest
 */
class GetTypeCest
{
    /**
     * Tests Phalcon\Http\Request\File :: getType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestFileGetType(UnitTester $I)
    {
        $I->wantToTest('Http\Request\File - getType()');
        $I->skipTest('Need implementation');
    }
}
