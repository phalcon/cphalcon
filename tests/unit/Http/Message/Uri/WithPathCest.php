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

/**
 * Class WithPathCest
 */
class WithPathCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withPath()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-09
     */
    public function httpMessageUriWithPath(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Uri - withPath() - ' . $example[0]);
        $query = 'https://dev.phalcon.ld%s';
        $uri   = new Uri(sprintf($query, '/action'));

        $newInstance = $uri->withPath($example[1]);
        $I->assertNotEquals($uri, $newInstance);
        $I->assertEquals($example[2], $newInstance->getPath());
        $I->assertEquals(sprintf($query, $example[3]), (string) $newInstance);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withPath() - exception no string
     *
     * @dataProvider getExceptions
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-07
     */
    public function httpUriWithPathException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withPath() - exception - ' . $example[1]);
        $I->expectThrowable(
            new InvalidArgumentException(
                'Uri:withPath() requires a string argument instead of ' . $example[0]
            ),
            function () use ($example) {
                $query    = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
                $uri      = new Uri($query);
                $instance = $uri->withPath($example[2]);
            }
        );
    }

    /**
     * @return array
     */
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
