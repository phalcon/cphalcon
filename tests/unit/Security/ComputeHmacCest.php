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

namespace Phalcon\Test\Unit\Security;

use UnitTester;
use Phalcon\Security;

/**
 * Class ComputeHmacCest
 */
class ComputeHmacCest
{
    /**
     * Tests the HMAC computation
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function securityComputeHmac(UnitTester $I)
    {
        $I->wantToTest('Security - computeHmac()');
        $security = new Security();

        $data = [];
        for ($i = 1; $i < 256; ++$i) {
            $data[] = str_repeat('a', $i);
        }
        $keys = [
            substr(md5('test', true), 0, strlen(md5('test', true)) / 2),
            md5('test', true),
            md5('test', true) . md5('test', true),
        ];

        foreach ($data as $index => $text) {
            $expected = hash_hmac('md5', $text, $keys[0]);
            $actual   = $security->computeHmac($text, $keys[0], 'md5');
            $I->assertEquals($expected, $actual);
            $expected = hash_hmac('md5', $text, $keys[1]);
            $actual   = $security->computeHmac($text, $keys[1], 'md5');
            $I->assertEquals($expected, $actual);
            $expected = hash_hmac('md5', $text, $keys[2]);
            $actual   = $security->computeHmac($text, $keys[2], 'md5');
            $I->assertEquals($expected, $actual);
        }
    }
}
