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

namespace Phalcon\Test\Unit\Http\Message\Uri;

use Codeception\Example;
use InvalidArgumentException;
use Phalcon\Http\Message\Uri;
use UnitTester;

class WithQueryCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withQuery()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-09
     */
    public function httpMessageUriWithQuery(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Uri - withQuery()');

        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?%s#frag';
        $uri   = new Uri(sprintf($query, 'param=value'));

        $newInstance = $uri->withQuery($example[1]);

        $I->assertNotEquals($uri, $newInstance);

        $I->assertEquals(
            $example[2],
            $newInstance->getQuery()
        );

        $I->assertEquals(
            sprintf($query, $example[2]),
            (string) $newInstance
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withQuery() - exception no string
     *
     * @dataProvider getExceptions
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-07
     */
    public function httpUriWithQueryException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withQuery() - exception - ' . $example[1]);

        $I->expectThrowable(
            new InvalidArgumentException(
                'Method requires a string argument'
            ),
            function () use ($example) {
                $uri = new Uri(
                    'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag'
                );

                $instance = $uri->withQuery($example[2]);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withQuery() - exception with fragment
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-07
     */
    public function httpUriWithQueryExceptionWithFragment(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - withQuery() - exception - with fragment');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Query cannot contain a query fragment'
            ),
            function () {
                $uri = new Uri(
                    'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag'
                );

                $instance = $uri->withQuery('/login#frag');
            }
        );
    }

    private function getExamples(): array
    {
        return [
            [
                'key only',
                'p^aram',
                'p%5Earam',
            ],
            [
                'key and value',
                'p^aram=valu`',
                'p%5Earam=valu%60',
            ],
            [
                'key as array',
                'param[]',
                'param%5B%5D',
            ],
            [
                'key as array and value',
                'param[]=valu`',
                'param%5B%5D=valu%60',
            ],
            [
                'key with questionmark',
                '?param=valu',
                'param=valu',
            ],
            [
                'complex',
                'p^aram&all[]=va lu`&f<>=`bar',
                'p%5Earam&all%5B%5D=va%20lu%60&f%3C%3E=%60bar',
            ],
        ];
    }

    private function getExceptions(): array
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
