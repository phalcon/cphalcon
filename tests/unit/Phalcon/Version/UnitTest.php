<?php
/**
 * UnitTest.php
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


use \Phalcon\Version as Version;
use \Codeception\TestCase\Test as CdTest;

class VersionUnitTest extends CdTest
{
    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testGet()
    {
        $actual = Version::get();

        expect(is_string($actual))->true();
    }

    /**
     * Tests the getId()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testGetId()
    {
        $actual = Version::getId();

        expect(is_string($actual))->true();
    }

    /**
     * Tests the get() translation to getId()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
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

        expect($expected)->equals($actual);
    }

    /**
     * Tests the getId() translation to get()
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
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

        expect($expected)->equals($actual);
    }

    /**
     * Tests the constants of the class
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testConstants()
    {
        expect(Version::VERSION_MAJOR)->equals(0);
        expect(Version::VERSION_MEDIUM)->equals(1);
        expect(Version::VERSION_MINOR)->equals(2);
        expect(Version::VERSION_SPECIAL)->equals(3);
        expect(Version::VERSION_SPECIAL_NUMBER)->equals(4);
    }

    public function testGetPart()
    {
        $id        = Version::getId();
        $major     = intval($id[Version::VERSION_MAJOR]);
        $med       = intval($id[Version::VERSION_MEDIUM] . $id[Version::VERSION_MINOR]);
        $min       = intval($id[Version::VERSION_SPECIAL] . $id[Version::VERSION_SPECIAL_NUMBER]);
        $special   = $this->_numberToSpecial($id[5]);
        $specialNo = ($special) ? $id[6] : '';

        expect($major)->equals(Version::getPart(Version::VERSION_MAJOR));
        expect($med)->equals(Version::getPart(Version::VERSION_MEDIUM));
        expect($min)->equals(Version::getPart(Version::VERSION_MINOR));
        expect($special)->equals(Version::getPart(Version::VERSION_SPECIAL));
        expect($specialNo)->equals(Version::getPart(Version::VERSION_SPECIAL_NUMBER));
        expect(Version::get())->equals(Version::getPart(7));
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
