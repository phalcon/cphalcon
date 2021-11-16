<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Http\Message\Uri;

use Codeception\Example;
use InvalidArgumentException;
use Phalcon\Http\Message\Uri;
use UnitTester;

use function sprintf;

class WithPortCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withPort()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-06-01
     */
    public function httpMessageUriWithPort(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Uri - withPort() - ' . $example[0]);

        $query = 'https://phalcon:secret@dev.phalcon.ld:%s/action?param=value#frag';

        $uri = new Uri(
            sprintf($query, ':4300')
        );

        $newInstance = $uri->withPort($example[1]);

        $I->assertNotEquals(
            $uri,
            $newInstance
        );

        $I->assertEquals(
            $example[2],
            $newInstance->getPort()
        );

        $I->assertEquals(
            sprintf($query, $example[3]),
            (string) $newInstance
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withPort() - exception no string
     *
     * @dataProvider getExceptions
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-07
     */
    public function httpUriWithPortException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withPort() - ' . $example[0]);

        $I->expectThrowable(
            new InvalidArgumentException(
                'Method expects ' . $example[2]
            ),
            function () use ($example) {
                $query = 'https://phalcon:secret@dev.phalcon.ld%s/action?param=value#frag';

                $uri = new Uri(
                    sprintf($query, ':4300')
                );

                $newInstance = $uri->withPort($example[1]);
            }
        );
    }


    private function getExamples(): array
    {
        return [
            [
                'null',
                null,
                null,
                '',
            ],
            [
                'int',
                8080,
                8080,
                ':8080',
            ],
            [
                'string-int',
                '8080',
                8080,
                ':8080',
            ],
            [
                'http',
                80,
                null,
                '',
            ],
            [
                'https',
                443,
                null,
                '',
            ],
        ];
    }


    private function getExceptions(): array
    {
        return [
            ['port less than 1', -2, 'valid port (1-65535)'],
            ['port more than max', 70000, 'valid port (1-65535)'],
        ];
    }
}
