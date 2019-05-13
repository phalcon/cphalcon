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
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-09
     */
    public function httpMessageUriWithQuery(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Uri - withQuery()');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?%s#frag';
        $uri   = new Uri(sprintf($query, 'param=value'));

        $newInstance = $uri->withQuery($example[1]);
        $I->assertNotEquals($uri, $newInstance);
        $I->assertEquals($example[2], $newInstance->getQuery());
        $I->assertEquals(sprintf($query, $example[2]), (string) $newInstance);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withQuery() - exception no string
     *
     * @dataProvider getExceptions
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-07
     */
    public function httpUriWithQueryException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withQuery() - exception - ' . $example[1]);
        $I->expectThrowable(
            new InvalidArgumentException(
                'Method requires a string argument instead of ' . $example[0]
            ),
            function () use ($example) {
                $query    = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
                $uri      = new Uri($query);
                $instance = $uri->withQuery($example[2]);
            }
        );
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            ['key only', 'p^aram', 'p%5Earam'],
            ['key and value', 'p^aram=valu`', 'p%5Earam=valu%60'],
            ['key as array', 'param[]', 'param%5B%5D'],
            ['key as array and value', 'param[]=valu`', 'param%5B%5D=valu%60'],
            ['complex', 'p^aram&all[]=va lu`&f<>=`bar', 'p%5Earam&all%5B%5D=va%20lu%60&f%3C%3E=%60bar'],
        ];
    }

    /**
     * @return array
     */
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
