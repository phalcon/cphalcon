<?php

namespace Phalcon\Test\Unit\Security;

use Phalcon\Test\Proxy\Security\Random;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Security\RandomTest
 * Tests for \Phalcon\Security\Random component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Security
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class RandomTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        if (!function_exists('random_bytes') && !extension_loaded('openssl') && !extension_loaded('libsodium') && !file_exists('/dev/urandom')) {
            $this->markTestSkipped(
                'Warning: libsodium and openssl extensions is not loaded, /dev/urandom file does not exists and random_bytes function does not exists'
            );
        }
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
            "number does not generated correct length of number",
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

                $random = new Random();

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
            "uuid does not created a properly formatted UUID",
            function () {
                $random = new Random();

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
            "base58 does not generate a valid string",
            function () {
                $lens = [
                    2,
                    12,
                    16,
                    24,
                    48,
                    100
                ];

                $random = new Random();

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
            "base64 does not generate a valid string",
            function () {
                $lens = [
                    2,
                    12,
                    16,
                    24,
                    48,
                    100
                ];

                $random = new Random();

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
            "base64Safe does not generate a valid string",
            function () {
                $lens = [
                    2,
                    12,
                    16,
                    24,
                    48,
                    100
                ];

                $random = new Random();

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
            "hex does not generate a valid string",
            function () {
                $lens = [
                    3,
                    6,
                    130,
                    19,
                    710,
                    943087
                ];

                $random = new Random();

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
            "bytes does not generate a valid string",
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

                $random = new Random();

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
