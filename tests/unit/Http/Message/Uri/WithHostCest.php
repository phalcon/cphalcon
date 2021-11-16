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

class WithHostCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withHost()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageUriWithHost(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - withHost()');

        $query = 'https://phalcon:secret@%s:8080/action?param=value#frag';

        $uri = new Uri(
            sprintf($query, 'dev.phalcon.ld')
        );

        $newInstance = $uri->withHost('prod.phalcon.ld');

        $I->assertNotEquals($uri, $newInstance);

        $I->assertEquals(
            'prod.phalcon.ld',
            $newInstance->getHost()
        );

        $I->assertEquals(
            sprintf($query, 'prod.phalcon.ld'),
            (string) $newInstance
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withHost() - exception no string
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-07
     */
    public function httpUriWithHostException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withHost() - exception - ' . $example[1]);

        $I->expectThrowable(
            new InvalidArgumentException(
                'Method requires a string argument'
            ),
            function () use ($example) {
                $uri = new Uri(
                    'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag'
                );

                $instance = $uri->withHost($example[2]);
            }
        );
    }


    private function getExamples(): array
    {
        return [
            [
                'NULL',
                'null',
                null,
            ],
            [
                'boolean',
                'true',
                true,
            ],
            [
                'boolean',
                'false',
                false,
            ],
            [
                'integer',
                'number',
                1234,
            ],
            [
                'array',
                'array',
                ['/action'],
            ],
            [
                'stdClass',
                'object',
                (object) ['/action'],
            ],
        ];
    }
}
