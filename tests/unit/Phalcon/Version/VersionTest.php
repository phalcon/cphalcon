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

use \Phalcon\Version as PhVersion;

class VersionTest extends \Codeception\TestCase\Test
{
    use \Codeception\Specify;

    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testGet()
    {
        $this->specify(
            "get() does not return a string",
            function () {

                $actual = PhVersion::get();

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
    public function testGetId()
    {
        $this->specify(
            "getId() does not return a string",
            function () {

                $actual = PhVersion::getId();

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
    public function testGetToGetId()
    {
        $this->specify(
            "get() to getId() does not produce the same result",
            function () {

                $version = PhVersion::get();
                $chunks  = explode(' ', $version);

                $special   = '4';
                $specialNo = '0';

                // There are special versions
                if (count($chunks) > 1)
                {
                    $specialNo = $chunks[2];
                    $special   = $this->_specialToNumber($chunks[1]);
                }

                // Now the version itself
                $verChunks = explode('.', $chunks[0]);
                $major = intval($verChunks[0]);
                $med   = substr("00" . intval($verChunks[1]), -2);
                $min   = substr("00" . intval($verChunks[2]), -2);

                $expected = "{$major}{$med}{$min}{$special}{$specialNo}";
                $actual   = PhVersion::getId();

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
    public function testGetIdToGet()
    {
        $this->specify(
            "getId() to get() does not produce the same result",
            function () {

                $id        = PhVersion::getId();
                $major     = intval($id[0]);
                $med       = intval($id[1] . $id[2]);
                $min       = intval($id[3] . $id[4]);
                $special   = $this->_numberToSpecial($id[5]);
                $specialNo = ($special) ? $id[6] : '';

                $expected = trim("{$major}.{$med}.{$min} {$special} {$specialNo}");
                $actual   = PhVersion::get();

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
    public function testConstants()
    {
        $this->specify(
            "VERSION_MAJOR does not return 0",
            function () {
                expect(PhVersion::VERSION_MAJOR)->equals(0);
            }
        );

        $this->specify(
            "VERSION_MEDIUM does not return 1",
            function () {
                expect(PhVersion::VERSION_MEDIUM)->equals(1);
            }
        );

        $this->specify(
            "VERSION_MINOR does not return 2",
            function () {
                expect(PhVersion::VERSION_MINOR)->equals(2);
            }
        );

        $this->specify(
            "VERSION_SPECIAL does not return 3",
            function () {
                expect(PhVersion::VERSION_SPECIAL)->equals(3);
            }
        );

        $this->specify(
            "VERSION_SPECIAL_NUMBER does not return 4",
            function () {
                expect(PhVersion::VERSION_SPECIAL_NUMBER)->equals(4);
            }
        );
    }

    /**
     * Tests the getPart with variable parameters passed, valid or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testGetPart()
    {
        $this->specify(
            "getPart(VERSION_MAJOR) does not return the correct result",
            function () {
                $id       = PhVersion::getId();
                $expected = intval($id[PhVersion::VERSION_MAJOR]);
                $actual   = PhVersion::getPart(PhVersion::VERSION_MAJOR);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart(VERSION_MEDIUM) does not return the correct result",
            function () {
                $id       = PhVersion::getId();
                $expected = intval($id[PhVersion::VERSION_MEDIUM]);
                $actual   = PhVersion::getPart(PhVersion::VERSION_MEDIUM);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart(VERSION_MINOR) does not return the correct result",
            function () {
                $id       = PhVersion::getId();
                $expected = intval($id[PhVersion::VERSION_MINOR]);
                $actual   = PhVersion::getPart(PhVersion::VERSION_MINOR);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart(VERSION_SPECIAL) does not return the correct result",
            function () {
                $id       = PhVersion::getId();
                $expected = $this->_numberToSpecial($id[5]);
                $actual   = PhVersion::getPart(PhVersion::VERSION_SPECIAL);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart(VERSION_SPECIAL_NUMBER) does not return the correct result",
            function () {
                $id       = PhVersion::getId();
                $special  = $this->_numberToSpecial($id[5]);
                $expected = ($special) ? $id[6] : '';
                $actual   = PhVersion::getPart(PhVersion::VERSION_SPECIAL_NUMBER);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "getPart() with incorrect parameters does not return get()",
            function () {
                $expected = PhVersion::get();
                $actual   = PhVersion::getPart(7);

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
    public function _specialToNumber($input)
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
    private function _numberToSpecial($number)
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
