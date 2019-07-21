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

use Codeception\Example;
use Phalcon\Security;
use UnitTester;

class ComputeHmacCest
{
    /**
     * Tests the HMAC computation
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2014-09-12
     *
     * @dataProvider securityComputeHmacProvider
     */
    public function securityComputeHmac(UnitTester $I, Example $example)
    {
        $I->wantToTest('Security - computeHmac()');

        $security = new Security();

        $keys = [
            substr(md5('test', true), 0, strlen(md5('test', true)) / 2),
            md5('test', true),
            md5('test', true) . md5('test', true),
        ];

        $text = $example[0];

        $I->assertEquals(
            hash_hmac('md5', $text, $keys[0]),
            $security->computeHmac($text, $keys[0], 'md5')
        );

        $I->assertEquals(
            hash_hmac('md5', $text, $keys[1]),
            $security->computeHmac($text, $keys[1], 'md5')
        );

        $I->assertEquals(
            hash_hmac('md5', $text, $keys[2]),
            $security->computeHmac($text, $keys[2], 'md5')
        );
    }

    private function securityComputeHmacProvider(): array
    {
        $data = [];

        for ($i = 1; $i < 256; ++$i) {
            $data[] = [
                str_repeat('a', $i),
            ];
        }

        return $data;
    }
}
