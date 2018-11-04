<?php

namespace Phalcon\Test\Unit;

use function is_string;
use Phalcon\Version;
use UnitTester;

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
class VersionCest
{
    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGet(UnitTester $I)
    {
        $actual = is_string(Version::get());
        $I->assertTrue($actual);
    }

    /**
     * Tests the getId()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGetId(UnitTester $I)
    {
        $actual = is_string(Version::getId());
        $I->assertTrue($actual);
    }

    /**
     * Tests the get() translation to getId()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGetToGetId(UnitTester $I)
    {
        $version = Version::get();
        $chunks  = explode(' ', $version);

        $special   = '4';
        $specialNo = '0';

        // There are special versions
        if (count($chunks) > 1) {
            $specialNo = $chunks[2];
            $special   = $this->specialToNumber($chunks[1]);
        }

        // Now the version itself
        $verChunks = explode('.', $chunks[0]);
        $major = intval($verChunks[0]);
        $med   = substr("00" . intval($verChunks[1]), -2);
        $min   = substr("00" . intval($verChunks[2]), -2);

        $expected = "{$major}{$med}{$min}{$special}{$specialNo}";
        $actual   = Version::getId();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the getId() translation to get()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGetIdToGet(UnitTester $I)
    {
        $id        = Version::getId();
        $major     = intval($id[0]);
        $med       = intval($id[1] . $id[2]);
        $min       = intval($id[3] . $id[4]);
        $special   = $this->numberToSpecial($id[5]);
        $specialNo = ($special) ? $id[6] : '';

        $expected = trim("{$major}.{$med}.{$min} {$special} {$specialNo}");
        $actual   = Version::get();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the constants of the class
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionConstants(UnitTester $I)
    {
        $I->assertEquals(0, Version::VERSION_MAJOR);
        $I->assertEquals(1, Version::VERSION_MEDIUM);
        $I->assertEquals(2, Version::VERSION_MINOR);
        $I->assertEquals(3, Version::VERSION_SPECIAL);
        $I->assertEquals(4, Version::VERSION_SPECIAL_NUMBER);
    }

    /**
     * Tests the getPart with variable parameters passed, valid or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGetPart(UnitTester $I)
    {
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

        $expected = intval($id[1].$id[2]); //The medium version is the second and third digits
        $actual   = Version::getPart(Version::VERSION_MEDIUM);
        $I->assertEquals($expected, $actual);

        $expected = intval($id[3].$id[4]); //The minor version is the fourth and fifth digits
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

    /**
     * Translates a special version (ALPHA, BETA, RC) to a version number
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param $input
     *
     * @return string
     */
    private function specialToNumber($input)
    {
        switch ($input) {
            case 'ALPHA':
                $special = '1';
                break;
            case 'BETA':
                $special = '2';
                break;
            case 'RC':
                $special = '3';
                break;
            default:
                $special = '4';
                break;
        }

        return $special;
    }

    /**
     * Translates a number to a special version string (ALPHA, BETA, RC)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param $number
     *
     * @return string
     */
    private function numberToSpecial($number)
    {
        $special = '';

        switch ($number) {
            case '1':
                $special = 'ALPHA';
                break;
            case '2':
                $special = 'BETA';
                break;
            case '3':
                $special = 'RC';
                break;
        }

        return $special;
    }
}
