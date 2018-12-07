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

namespace Phalcon\Test\Unit\Assets\Exception;

use UnitTester;

/**
 * Class GetFileCest
 *
 * @package Phalcon\Test\Unit\Assets\Exception
 */
class GetFileCest
{
    /**
     * Tests Phalcon\Assets\Exception :: getFile()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsExceptionGetFile(UnitTester $I)
    {
        $I->wantToTest("Assets\Exception - getFile()");
        $I->skipTest("Need implementation");
    }
}
