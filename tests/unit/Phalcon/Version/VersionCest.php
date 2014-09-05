<?php
/**
 * VersionCest.php
 * \Phalcon\Version
 *
 * Tests the \Phalcon\Version component
 *
 * PhalconPHP Framework
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

use \CodeGuy;
use \Phalcon\Version as Version;

class VersionCest
{
    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testGet(CodeGuy $I)
    {
        $actual = PhVersion::get();

        $I->assertTrue(
            is_string($actual),
            'get() does not return a string'
        );
    }

    /**
     * Tests the getId()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testGetId(CodeGuy $I)
    {
        $actual = PhVersion::getId();

        $I->assertTrue(
            is_string($actual),
            'getId() does not return a string'
        );
    }

    /**
     * Tests the get() translation to getId()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testGetToGetId(CodeGuy $I)
    {
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

        $I->assertEquals($expected, $actual, 'get() to getId() failed');
    }

    /**
     * Tests the getId() translation to get()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testGetIdToGet(CodeGuy $I)
    {
        $id        = PhVersion::getId();
        $major     = intval($id[0]);
        $med       = intval($id[1] . $id[2]);
        $min       = intval($id[3] . $id[4]);
        $special   = $this->_numberToSpecial($id[5]);
        $specialNo = ($special) ? $id[6] : '';

        $expected = trim("{$major}.{$med}.{$min} {$special} {$specialNo}");
        $actual   = PhVersion::get();

        $I->assertEquals($expected, $actual, 'getId() to get() failed');
    }

    /**
     * Tests the constants of the class
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testConstants(CodeGuy $I)
    {
        $I->assertEquals(PhVersion::VERSION_MAJOR, 0, 'VERSION_MAJOR is not 0');
        $I->assertEquals(PhVersion::VERSION_MEDIUM, 1, 'VERSION_MEDIUM is not 1');
        $I->assertEquals(PhVersion::VERSION_MINOR, 2, 'VERSION_MINOR is not 2');
        $I->assertEquals(PhVersion::VERSION_SPECIAL, 3, 'VERSION_SPECIAL is not 3');
        $I->assertEquals(PhVersion::VERSION_SPECIAL_NUMBER, 4, 'VERSION_SPECIAL_NUMBER is not 4');
    }

    /**
     * Tests the getPart with variable parameters passed, valid or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testGetPart(CodeGuy $I)
    {
        $id        = PhVersion::getId();
        $major     = intval($id[PhVersion::VERSION_MAJOR]);
        $med       = intval($id[PhVersion::VERSION_MEDIUM] . $id[PhVersion::VERSION_MINOR]);
        $min       = intval($id[PhVersion::VERSION_SPECIAL] . $id[PhVersion::VERSION_SPECIAL_NUMBER]);
        $special   = $this->_numberToSpecial($id[5]);
        $specialNo = ($special) ? $id[6] : '';

        $I->assertEquals(
            $major,
            PhVersion::getPart(PhVersion::VERSION_MAJOR),
            'Major version does not match'
        );

        $I->assertEquals(
            $med,
            PhVersion::getPart(PhVersion::VERSION_MEDIUM),
            'Medium version does not match'
        );

        $I->assertEquals(
            $min,
            PhVersion::getPart(PhVersion::VERSION_MINOR),
            'Minor version does not match'
        );

        $I->assertEquals(
            $special,
            PhVersion::getPart(PhVersion::VERSION_SPECIAL),
            'Special version does not match'
        );

        $I->assertEquals(
            $specialNo,
            PhVersion::getPart(PhVersion::VERSION_SPECIAL_NUMBER),
            'Special number does not match'
        );

        $I->assertEquals(
            PhVersion::get(),
            PhVersion::getPart(7),
            'Invalid parameter does not return get()'
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
