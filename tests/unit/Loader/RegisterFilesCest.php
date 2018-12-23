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

namespace Phalcon\Test\Unit\Loader;

use UnitTester;

/**
 * Class RegisterFilesCest
 */
class RegisterFilesCest
{
    /**
     * Tests Phalcon\Loader :: registerFiles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loaderRegisterFiles(UnitTester $I)
    {
        $I->wantToTest('Loader - registerFiles()');
        $I->skipTest('Need implementation');
    }
}
