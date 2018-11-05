<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Security;

use Phalcon\Security\Random;
use UnitTester;

class RandomCest
{
    /**
     * executed before each test
     */
    protected function _before(UnitTester $I, $scenario)
    {
        if (!function_exists('random_bytes') &&
            !extension_loaded('openssl') &&
            !extension_loaded('libsodium') &&
            !file_exists('/dev/urandom')) {
            $scenario->skip(
                'Warning: libsodium and openssl extensions is not loaded or ' .
                '/dev/urandom file does not exist or ' .
                'random_bytes function does not exists'
            );
        }
    }

    /**
     * Tests the random number generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomNumber(UnitTester $I)
    {
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
            $I->assertLessOrEquals($len, $actual);
            $I->assertGreaterOrEquals(0, $actual);
        }
    }

    /**
     * Tests the random UUID v4 generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomUuid(UnitTester $I)
    {
        $random = new Random();

        $isValid = function ($uuid) {
            return (
                preg_match(
                    '/^\{?[0-9a-f]{8}\-?[0-9a-f]{4}\-?[0-9a-f]{4}\-?[0-9a-f]{4}\-?[0-9a-f]{12}\}?$/i',
                    $uuid
                ) === 1);
        };

        for ($i = 0; $i <= 10; $i++) {
            $uuid = $random->uuid();

            $I->assertTrue($isValid($uuid));

            $expected = 4;
            $actual   = substr($uuid, 14, 1);
            $I->assertEquals($expected, $actual);

            $actual = in_array(substr($uuid, 19, 1), ['8', '9', 'a', 'b']);
            $I->assertTrue($actual);
        }
    }

    /**
     * Tests the random base58 generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-20
     */
    public function testRandomBase58(UnitTester $I)
    {
        $examples = [null, 2, 12, 16, 24, 48, 100];

        foreach ($examples as $len) {
            $random = new Random();

            $isValid = function ($base58) {
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

            $base58 = $random->base58($len);

            $expected = ($len === null) ? 16 : $len;
            $actual   = strlen($base58);
            $I->assertEquals($expected, $actual);
            $I->assertTrue($isValid($actual));
        }
    }

    /**
     * Tests the random base62 generation
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12105
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-05-21
     */
    public function testRandomBase62(UnitTester $I)
    {
        $examples = [null, 2, 12, 16, 24, 48, 100];

        foreach ($examples as $len) {
            $random = new Random();

            $isValid = function ($base62) {
                return (preg_match("#^[^a-z0-9]+$#i", $base62) === 0);
            };

            $base62 = $random->base62($len);

            $expected = ($len === null) ? 16 : $len;
            $actual   = strlen($base62);
            $I->assertEquals($expected, $actual);
            $I->assertTrue($isValid($actual));
        }
    }

    /**
     * Tests the random base64 generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomBase64(UnitTester $I)
    {
        $examples = [null, 2, 12, 16, 24, 48, 100];

        foreach ($examples as $len) {
            $random = new Random();

            $isValid = function ($base64) {
                return (preg_match("#[^a-z0-9+_=/-]+#i", $base64) === 0);
            };

            $base64 = $random->base64($len);

            $expected = ($len === null) ? 16 : $len;
            $actual   = strlen($base64);
            $I->assertTrue($this->checkSize($base64, $expected));
            $I->assertTrue($isValid($actual));
        }
    }

    /**
     * Tests the random base64 generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomBase64Safe(UnitTester $I)
    {
        $examples = [
            [null, false, 'a-z0-9_-' ],
            [null, true,  'a-z0-9_=-'],
            [2,    false, 'a-z0-9_-' ],
            [2,    true,  'a-z0-9_=-'],
            [12,   false, 'a-z0-9_-' ],
            [12,   true,  'a-z0-9_=-'],
            [16,   false, 'a-z0-9_-' ],
            [16,   true,  'a-z0-9_=-'],
            [24,   false, 'a-z0-9_-' ],
            [24,   true,  'a-z0-9_=-'],
            [48,   false, 'a-z0-9_-' ],
            [48,   true,  'a-z0-9_=-'],
            [100,  false, 'a-z0-9_-' ],
            [100,  true,  'a-z0-9_=-'],
        ];

        foreach ($examples as $example) {
            $len     = $example[0];
            $padding = $example[1];
            $pattern = $example[2];

            $random = new Random();

            $isValid = function ($base64) use ($pattern) {
                return (preg_match("#[^$pattern]+#i", $base64) === 0);
            };

            $actual = $random->base64Safe($len, $padding);
            $I->assertTrue($isValid($actual));
        }
    }

    /**
     * Tests the random hex generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomHex(UnitTester $I)
    {
        $lens = [
            3,
            6,
            130,
            19,
            710,
            943087
        ];

        $random = new Random();

        $checkSize = function ($hex, $len) {
            return strlen($hex) == $len * 2;
        };

        $isValid = function ($hex) {
            return (preg_match("#^[^0-9a-f]+$#i", $hex) === 0);
        };

        foreach ($lens as $len) {
            $hex = $random->hex($len);

            $actual = $checkSize($hex, $len);
            $I->assertTrue($actual);

            $actual = $isValid($hex);
            $I->assertTrue($actual);
        }

        $hex = $random->hex();

        $actual = $checkSize($hex, 16);
        $I->assertTrue($actual);

        $actual = $isValid($hex);
        $I->assertTrue($actual);
    }

    /**
     * Tests the random bytes string generation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-08-17
     */
    public function testRandomByte(UnitTester $I)
    {
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
        $isValid = function ($bytes) {
            return (preg_match('#^[^\x00-\xFF]+$#', $bytes) === 0);
        };

        foreach ($lens as $len) {
            $bytes = $random->bytes($len);

            $expected = $len;
            $actual   = strlen($bytes);
            $I->assertEquals($expected, $actual);
            $I->assertTrue($isValid($bytes));
        }

        $bytes = $random->bytes();

        $expected = 16;
        $actual   = strlen($bytes);
        $I->assertEquals($expected, $actual);
        $I->assertTrue($isValid($bytes));
    }

    /**
     * Size formula: 4 * ($n / 3) and this need to be rounded up to a multiple of 4.
     *
     * @param string $string
     * @param int $n
     *
     * @return bool
     */
    protected function checkSize($string, $n)
    {
        if (round(4 * ($n / 3)) % 4 === 0) {
            $len = round(4 * ($n / 3));
        } else {
            $len = round((4 * ($n / 3) + 4 / 2) / 4) * 4;
        }

        return strlen($string) == $len;
    }
}
