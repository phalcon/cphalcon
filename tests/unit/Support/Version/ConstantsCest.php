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
     * @since  2020-09-09
     */
    public function supportVersionConstants(UnitTester $I)
    {
        $I->wantToTest('Version - constants');

        $I->assertSame(0, Version::VERSION_MAJOR);
        $I->assertSame(1, Version::VERSION_MEDIUM);
        $I->assertSame(2, Version::VERSION_MINOR);
        $I->assertSame(3, Version::VERSION_SPECIAL);
        $I->assertSame(4, Version::VERSION_SPECIAL_NUMBER);
    }
}
