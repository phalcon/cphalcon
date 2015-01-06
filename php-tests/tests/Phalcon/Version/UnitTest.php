<?php
/**
 * UnitTest.php
 * \Phalcon\Version\UnitTest
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

namespace Phalcon\Test\Version;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Version as Version;

class UnitTest extends PhTestUnitTestCase
{
    /**
     * Tests the get
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testGet()
    {
        $actual = Version::get();

        $this->assertTrue(is_string($actual));
    }

    /**
     * Tests the getId()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testGetId()
    {
        $actual = Version::getId();

        $this->assertTrue(is_string($actual));
    }

    /**
     * Tests the get() translation to getId()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testGetToGetId()
    {
        $version = Version::get();
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
        $actual   = Version::getId();

        $this->assertEquals(
            $expected,
            $actual,
            "Version get to getId does not translate properly"
        );
    }

    /**
     * Tests the getId() translation to get()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testGetIdToGet()
    {
        $id        = Version::getId();
        $major     = intval($id[0]);
        $med       = intval($id[1] . $id[2]);
        $min       = intval($id[3] . $id[4]);
        $special   = $this->_numberToSpecial($id[5]);
        $specialNo = ($special) ? $id[6] : '';

        $expected = trim("{$major}.{$med}.{$min} {$special} {$specialNo}");
        $actual   = Version::get();

        $this->assertEquals(
            $actual,
            $expected,
            "Version getId to get does not translate properly"
        );
    }

    /**
     * Translates a special version (ALPHA, BETA, RC) to a version number
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
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
