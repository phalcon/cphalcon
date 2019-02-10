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
 * Class MoveToCest
 */
class MoveToCest
{
    /**
     * Tests Phalcon\Http\Request\File :: moveTo()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpRequestFileMoveTo(UnitTester $I)
    {
        $I->wantToTest('Http\Request\File - moveTo()');
        $I->skipTest('Need implementation');
    }
}
