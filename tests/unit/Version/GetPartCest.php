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

use Phalcon\Test\Fixtures\Traits\VersionTrait;
use Phalcon\Version;
use UnitTester;

class GetPartCest
{
    use VersionTrait;

    /**
     * Tests Phalcon\Version :: getPart()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function versionGetPart(UnitTester $I)
    {
        $I->wantToTest('Version - getPart()');

        /*
         * Note: getId() returns a version string in the format ABBCCDE
         * where A is the major version, BB is the medium version (2 digits)
         * CC is the minor version (2 digits), D is the release type (see
         * Phalcon\Version) and E is the release number (for example 2 for RC2)
         */

        $id = Version::getId();

        // The major version is the first digit
        $I->assertEquals(
            intval($id[0]),
            Version::getPart(Version::VERSION_MAJOR)
        );

        // The medium version is the second and third digits
        $I->assertEquals(
            intval($id[1] . $id[2]),
            Version::getPart(Version::VERSION_MEDIUM)
        );

        // The minor version is the fourth and fifth digits
        $I->assertEquals(
            intval($id[3] . $id[4]),
            Version::getPart(Version::VERSION_MINOR)
        );

        $I->assertEquals(
            $this->numberToSpecial($id[5]),
            Version::getPart(Version::VERSION_SPECIAL)
        );

        $special  = $this->numberToSpecial($id[5]);
        $expected = ($special) ? $id[6] : 0;
        $I->assertEquals(
            $expected,
            Version::getPart(Version::VERSION_SPECIAL_NUMBER)
        );

        $I->assertEquals(
            Version::get(),
            Version::getPart(7)
        );
    }
}
