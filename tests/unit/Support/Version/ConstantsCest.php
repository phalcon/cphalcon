<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Version;

use Phalcon\Support\Version;
use UnitTester;

class ConstantsCest
{
    /**
     * Tests Phalcon\Support\Version :: Constants
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportVersionConstants(UnitTester $I)
    {
        $I->wantToTest('Version - constants');

        $I->assertEquals(0, Version::VERSION_MAJOR);
        $I->assertEquals(1, Version::VERSION_MEDIUM);
        $I->assertEquals(2, Version::VERSION_MINOR);
        $I->assertEquals(3, Version::VERSION_SPECIAL);
        $I->assertEquals(4, Version::VERSION_SPECIAL_NUMBER);
    }
}
