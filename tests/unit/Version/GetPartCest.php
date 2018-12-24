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

/**
 * Class GetPartCest
 */
class GetPartCest
{
    use VersionTrait;

    /**
     * Tests Phalcon\Version :: getPart()
     *
     * @param UnitTester $I
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
         * CC is the minor version (2 digits), D is the release type (see Phalcon\Version)
         * and E is the release number (for example 2 for RC2)
         */

        $id       = Version::getId();
        $expected = intval($id[0]); //The major version is the first digit
        $actual   = Version::getPart(Version::VERSION_MAJOR);
        $I->assertEquals($expected, $actual);

        $expected = intval($id[1] . $id[2]); //The medium version is the second and third digits
        $actual   = Version::getPart(Version::VERSION_MEDIUM);
        $I->assertEquals($expected, $actual);

        $expected = intval($id[3] . $id[4]); //The minor version is the fourth and fifth digits
        $actual   = Version::getPart(Version::VERSION_MINOR);
        $I->assertEquals($expected, $actual);

        $expected = $this->numberToSpecial($id[5]);
        $actual   = Version::getPart(Version::VERSION_SPECIAL);
        $I->assertEquals($expected, $actual);

        $special  = $this->numberToSpecial($id[5]);
        $expected = ($special) ? $id[6] : 0;
        $actual   = Version::getPart(Version::VERSION_SPECIAL_NUMBER);
        $I->assertEquals($expected, $actual);

        $expected = Version::get();
        $actual   = Version::getPart(7);
        $I->assertEquals($expected, $actual);
    }
}
