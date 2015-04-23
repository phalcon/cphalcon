<?php
/**
 * VersionTest.php
 * \Phalcon\Version
 *
 * Tests the \Phalcon\Version component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Version;

use \PhalconTest\Version as PhTVersion;
use \Codeception\TestCase\Test as CdTest;
use \Codeception\Specify as CdSpecify;

class VersionTest extends CdTest
{
    use CdSpecify;

    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGet()
    {
        $this->specify(
            "get() does not return a string",
            function () {

                $actual = PhTVersion::get();

                expect(is_string($actual))->true();
            }
        );
    }

    /**
     * Tests the getId()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGetId()
    {
        $this->specify(
            "getId() does not return a string",
            function () {

                $actual = PhTVersion::getId();

                expect(is_string($actual))->true();
            }
        );
    }

    /**
     * Tests the get() translation to getId()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGetToGetId()
    {
        $this->specify(
            "get() to getId() does not produce the same result",
            function () {

                $version = PhTVersion::get();
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
                $actual   = PhTVersion::getId();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the getId() translation to get()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGetIdToGet()
    {
        $this->specify(
            "getId() to get() does not produce the same result",
            function () {

                $id        = PhTVersion::getId();
                $major     = intval($id[0]);
                $med       = intval($id[1] . $id[2]);
                $min       = intval($id[3] . $id[4]);
                $special   = $this->numberToSpecial($id[5]);
                $specialNo = ($special) ? $id[6] : '';

                $expected = trim("{$major}.{$med}.{$min} {$special} {$specialNo}");
                $actual   = PhTVersion::get();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the constants of the class
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionConstants()
    {
        $this->specify(
            "VERSION_MAJOR does not return 0",
            function () {
                expect(PhTVersion::VERSION_MAJOR)->equals(0);
            }
        );

        $this->specify(
            "VERSION_MEDIUM does not return 1",
            function () {
                expect(PhTVersion::VERSION_MEDIUM)->equals(1);
            }
        );

        $this->specify(
            "VERSION_MINOR does not return 2",
            function () {
                expect(PhTVersion::VERSION_MINOR)->equals(2);
            }
        );

        $this->specify(
            "VERSION_SPECIAL does not return 3",
            function () {
                expect(PhTVersion::VERSION_SPECIAL)->equals(3);
            }
        );

        $this->specify(
            "VERSION_SPECIAL_NUMBER does not return 4",
            function () {
                expect(PhTVersion::VERSION_SPECIAL_NUMBER)->equals(4);
            }
        );
    }

    /**
     * Tests the getPart with variable parameters passed, valid or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testVersionGetPart()
    {
        /*
         * Note: getId() returns a version string in the format ABBCCDE
         * where A is the major version, BB is the medium version (2 digits)
         * CC is the minor version (2 digits), D is the release type (see Phalcon\Version)
         * and E is the release number (for example 2 for RC2)
         */

        $this->specify(
            "getPart(VERSION_MAJOR) does not return the correct result",
            function () {

                $id       = PhTVersion::getId();
                $expected = intval($id[0]); //The major version is the first digit
                $actual   = PhTVersion::getPart(PhTVersion::VERSION_MAJOR);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart(VERSION_MEDIUM) does not return the correct result",
            function () {
                $id       = PhTVersion::getId();
                $expected = intval($id[1].$id[2]); //The medium version is the second and third digits
                $actual   = PhTVersion::getPart(PhTVersion::VERSION_MEDIUM);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart(VERSION_MINOR) does not return the correct result",
            function () {
                $id       = PhTVersion::getId();
                $expected = intval($id[3].$id[4]); //The minor version is the fourth and fifth digits
                $actual   = PhTVersion::getPart(PhTVersion::VERSION_MINOR);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart(VERSION_SPECIAL) does not return the correct result",
            function () {
                $id       = PhTVersion::getId();
                $expected = $this->numberToSpecial($id[5]);
                $actual   = PhTVersion::getPart(PhTVersion::VERSION_SPECIAL);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart(VERSION_SPECIAL_NUMBER) does not return the correct result",
            function () {
                $id       = PhTVersion::getId();
                $special  = $this->numberToSpecial($id[5]);
                $expected = ($special) ? $id[6] : 0;
                $actual   = PhTVersion::getPart(PhTVersion::VERSION_SPECIAL_NUMBER);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart() with incorrect parameters does not return get()",
            function () {
                $expected = PhTVersion::get();
                $actual   = PhTVersion::getPart(7);

                expect($actual)->equals($expected);
            }
        );
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
        switch ($input)
        {
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

        switch ($number)
        {
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
