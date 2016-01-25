<?php
/**
 * RandomTest.php
 * \Phalcon\Security\Random
 *
 * Tests the \Phalcon\Security\Random component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Security;

use \PhalconTest\Security\Random as PhTRandom;
use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class RandomTest extends TBase
{
    public function _before()
    {
        if (!extension_loaded('openssl') && !extension_loaded('libsodium') && !file_exists("/dev/urandom")) {
            $this->markTestSkipped('Warning: libsodium or openssl extensions is not loaded and /dev/urandom file does not exists');
            return;
        }

        parent::_before();
    }

    /**
     * Tests the random number generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomNumber()
    {
        $this->specify(
            "The random number generation less or equals \$len and greater or equals 0",
            function () {
                $lens = [
                    2,
                    100,
                    9,
                    8777,
                    123456789,
                    1,
                    9999999999999
                ];

                $random = new PhTRandom();

                foreach ($lens as $len) {
                    $actual = $random->number($len);

                    expect($actual)->lessOrEquals($len);
                    expect($actual)->greaterOrEquals(0);
                }
            }
        );
    }

    /**
     * Tests the random UUID v4 generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomUuid()
    {
        $this->specify(
            "The v4 random method created a properly formatted UUID",
            function () {
                $random = new PhTRandom();

                $isValid = function($uuid) {
                    return (preg_match('/^\{?[0-9a-f]{8}\-?[0-9a-f]{4}\-?[0-9a-f]{4}\-?[0-9a-f]{4}\-?[0-9a-f]{12}\}?$/i', $uuid) === 1);
                };

                for ($i = 0; $i <= 10; $i++) {
                    $actual = $random->uuid();

                    expect($isValid($actual))->true();
                    expect(substr($actual, 14, 1))->equals(4);
                    expect(in_array(substr($actual, 19, 1), ['8', '9', 'a', 'b']))->true();
                }
            }
        );
    }

    /**
     * Tests the random base58 generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-20
     */
    public function testRandomBase58()
    {
        $this->specify(
            "The base58 string contains valid chars and result is valid size",
            function () {
                $lens = [
                    2,
                    12,
                    16,
                    24,
                    48,
                    100
                ];

                $random = new PhTRandom();

                $isValid = function($base58) {
                    $alphabet = array_merge(
                        range("A", "H"),
                        range("J", "N"),
                        range("P", "Z"),
                        range("a", "k"),
                        range("m", "z"),
                        range("1", "9")
                    );

                    return (preg_match('#^[^'.join('', $alphabet).']+$#i', $base58) === 0);
                };

                foreach ($lens as $len) {
                    $actual = $random->base58($len);

                    expect(strlen($actual))->equals($len);
                    expect($isValid($actual))->true();
                }

                $actual = $random->base58();
                expect(strlen($actual))->equals(16);
                expect($isValid($actual))->true();
            }
        );
    }

    /**
     * Tests the random base64 generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomBase64()
    {
        $this->specify(
            "The base64 string contains valid chars and result is valid size",
            function () {
                $lens = [
                    2,
                    12,
                    16,
                    24,
                    48,
                    100
                ];

                $random = new PhTRandom();

                $checkSize = function($base64, $len) {
                    // Size formula: 4 *( $len / 3) and this need to be rounded up to a multiple of 4.
                    $formula = (round(4*($len/3))%4 === 0) ? round(4*($len/3)) : round((4*($len/3)+4/2)/4)*4;

                    return strlen($base64) == $formula;
                };

                $isValid = function($base64) {
                    return (preg_match("#[^a-z0-9+_=/-]+#i", $base64) === 0);
                };

                foreach ($lens as $len) {
                    $actual = $random->base64($len);

                    expect($checkSize($actual, $len))->true();
                    expect($isValid($actual))->true();
                }

                $actual = $random->base64();
                expect($checkSize($actual, 16))->true();
                expect($isValid($actual))->true();
            }
        );
    }

    /**
     * Tests the random base64 generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomBase64Safe()
    {
        $this->specify(
            "The base64 string contains safe and valid chars and result is valid size",
            function () {
                $lens = [
                    2,
                    12,
                    16,
                    24,
                    48,
                    100
                ];

                $random = new PhTRandom();

                $getSize = function($len) {
                    // Size formula: 4 *( $len / 3) and this need to be rounded up to a multiple of 4.
                    return (int)(round(4*($len/3))%4 === 0) ? round(4*($len/3)) : round((4*($len/3)+4/2)/4)*4;
                };

                $isValid = function($base64, $padding = false) {
                    $pattern = $padding ? "a-z0-9_=-" : "a-z0-9_-";
                    return (preg_match("#[^$pattern]+#i", $base64) === 0);
                };

                foreach ($lens as $len) {
                    $actual = $random->base64Safe($len);
                    expect(strlen($actual))->lessOrEquals($getSize($len));
                    expect($isValid($actual))->true();
                }

                $actual = $random->base64Safe();
                expect(strlen($actual))->lessOrEquals($getSize(16));
                expect($isValid($actual))->true();

                $actual = $random->base64Safe(null, true);
                expect(strlen($actual))->lessOrEquals($getSize(16));
                expect($isValid($actual, true))->true();
            }
        );
    }

    /**
     * Tests the random hex generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomHex()
    {
        $this->specify(
            "The hex string contains valid chars and result is valid size",
            function () {
                $lens = [
                    3,
                    6,
                    130,
                    19,
                    710,
                    943087
                ];

                $random = new PhTRandom();

                $checkSize = function($hex, $len) {
                    return strlen($hex) == $len * 2;
                };

                $isValid = function($hex) {
                    return (preg_match("#^[^0-9a-f]+$#i", $hex) === 0);
                };

                foreach ($lens as $len) {
                    $actual = $random->hex($len);

                    expect($checkSize($actual, $len))->true();
                    expect($isValid($actual))->true();
                }

                $actual = $random->hex();
                expect($checkSize($actual, 16))->true();
                expect($isValid($actual))->true();
            }
        );
    }

    /**
     * Tests the random bytes string generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomByte()
    {
        $this->specify(
            "The random bytes string contains valid chars and result is valid size",
            function () {
                $lens = [
                    3,
                    6,
                    19,
                    222,
                    100,
                    9090909,
                    12312312
                ];

                $random = new PhTRandom();

                $isValid = function($bytes) {
                    return (preg_match('#^[^\x00-\xFF]+$#', $bytes) === 0);
                };

                foreach ($lens as $len) {
                    $actual = $random->bytes($len);

                    expect(strlen($actual))->equals($len);
                    expect($isValid($actual))->true();
                }

                $actual = $random->bytes();
                expect(strlen($actual))->equals(16);
                expect($isValid($actual))->true();
            }
        );
    }
}
