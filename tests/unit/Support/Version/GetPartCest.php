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
use Phalcon\Tests\Fixtures\Traits\VersionTrait;
use UnitTester;

class GetPartCest
{
    use VersionTrait;

    /**
     * Tests Phalcon\Support\Version :: getPart()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportVersionGetPart(UnitTester $I)
    {
        $I->wantToTest('Version - getPart()');

        /*
         * Note: getId() returns a version string in the format ABBCCDE
         * where A is the major version, BB is the medium version (2 digits)
         * CC is the minor version (2 digits), D is the release type (see
         * Phalcon\Support\Version) and E is the release number (for example 2 for RC2)
         */

        $version = new Version();
        $id      = $version->getId();

        // The major version is the first digit
        $I->assertEquals(
            intval($id[0]),
            $version->getPart(Version::VERSION_MAJOR)
        );

        // The medium version is the second and third digits
        $I->assertEquals(
            intval($id[1] . $id[2]),
            $version->getPart(Version::VERSION_MEDIUM)
        );

        // The minor version is the fourth and fifth digits
        $I->assertEquals(
            intval($id[3] . $id[4]),
            $version->getPart(Version::VERSION_MINOR)
        );

        $I->assertEquals(
            $this->numberToSpecial($id[5]),
            $version->getPart(Version::VERSION_SPECIAL)
        );

        $special  = $this->numberToSpecial($id[5]);
        $expected = ($special) ? $id[6] : 0;
        $I->assertEquals(
            $expected,
            $version->getPart(Version::VERSION_SPECIAL_NUMBER)
        );

        $I->assertEquals($version->get(), $version->getPart(7));
    }
}
