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

class WithSchemeCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withScheme()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-09
     */
    public function httpMessageUriWithScheme(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - withScheme()');

        $query = '%s://phalcon:secret@dev.phalcon.ld:8000/action?param=value#frag';

        $uri = new Uri(
            sprintf($query, 'https')
        );

        $newInstance = $uri->withScheme('http');

        $I->assertNotEquals($uri, $newInstance);

        $I->assertEquals(
            'http',
            $newInstance->getScheme()
        );

        $I->assertEquals(
            sprintf($query, 'http'),
            (string) $newInstance
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withScheme() - exception unsupported
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-06-01
     */
    public function httpUriWithSchemeExceptionUnsupported(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - withScheme() - exception - unsupported');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Unsupported scheme [ftp]. Scheme must be one of [http, https]'
            ),
            function () {
                $uri = new Uri(
                    'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag'
                );

                $instance = $uri->withScheme('ftp');
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withScheme() - exception no string
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-07
     */
    public function httpUriWithSchemeException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withScheme() - exception - ' . $example[1]);

        $I->expectThrowable(
            new InvalidArgumentException(
                'Method requires a string argument'
            ),
            function () use ($example) {
                $uri = new Uri(
                    'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag'
                );

                $instance = $uri->withScheme($example[2]);
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
