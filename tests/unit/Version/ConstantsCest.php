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

namespace Phalcon\Test\Unit\Version;

use Phalcon\Version;
use UnitTester;

/**
 * Class ConstantsCest
 */
class ConstantsCest
{
    /**
     * Tests Phalcon\Version :: Constants
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function versionConstants(UnitTester $I)
    {
        $I->wantToTest('Version - constants');
        $I->assertEquals(0, Version::VERSION_MAJOR);
        $I->assertEquals(1, Version::VERSION_MEDIUM);
        $I->assertEquals(2, Version::VERSION_MINOR);
        $I->assertEquals(3, Version::VERSION_SPECIAL);
        $I->assertEquals(4, Version::VERSION_SPECIAL_NUMBER);
    }
}
