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

class WithPathCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withPath()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-09
     */
    public function httpMessageUriWithPath(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Uri - withPath() - ' . $example[0]);

        $query = 'https://dev.phalcon.ld%s';

        $uri = new Uri(
            sprintf($query, '/action')
        );

        $newInstance = $uri->withPath(
            $example[1]
        );

        $I->assertNotEquals(
            $uri,
            $newInstance
        );

        $I->assertEquals(
            $example[2],
            $newInstance->getPath()
        );

        $I->assertEquals(
            sprintf($query, $example[3]),
            (string) $newInstance
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withPath() - exception query string
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-06-01
     */
    public function httpUriWithPathExceptionQueryString(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - withPath() - exception - query string');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Path cannot contain a query string or fragment'
            ),
            function () {
                $query    = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
                $uri      = new Uri($query);
                $instance = $uri->withPath('/login?param=value');
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withPath() - exception query fragment
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-06-01
     */
    public function httpUriWithPathExceptionQueryFragment(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - withPath() - exception - query fragment');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Path cannot contain a query string or fragment'
            ),
            function () {
                $query    = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
                $uri      = new Uri($query);
                $instance = $uri->withPath('/login#frag');
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withPath() - exception no string
     *
     * @dataProvider getExceptions
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-07
     */
    public function httpUriWithPathException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withPath() - exception - ' . $example[1]);

        $I->expectThrowable(
            new InvalidArgumentException(
                'Method requires a string argument'
            ),
            function () use ($example) {
                $query    = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
                $uri      = new Uri($query);
                $instance = $uri->withPath($example[2]);
            }
        );
    }


    private function getExamples(): array
    {
        return [
            ['empty', '', '', ''],
            ['normal', '/login', '/login', '/login'],
            ['double slash', '//login', '/login', '/login'],
            ['no leading slash', 'login', 'login', '/login'],
            ['garbled', '/l^ogin/si gh', '/l%5Eogin/si%20gh', '/l%5Eogin/si%20gh'],
        ];
    }


    private function getExceptions(): array
    {
        return [
            ['NULL', 'null', null],
            ['boolean', 'true', true],
            ['boolean', 'false', false],
            ['integer', 'number', 1234],
            ['array', 'array', ['/action']],
            ['stdClass', 'object', (object) ['/action']],
        ];
    }
}
