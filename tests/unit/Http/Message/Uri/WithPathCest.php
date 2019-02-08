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

namespace Phalcon\Test\Unit\Http\Uri;

use Codeception\Example;
use Phalcon\Http\Uri;
use UnitTester;

/**
 * Class WithPathCest
 */
class WithPathCest
{
    /**
     * Tests Phalcon\Http\Uri :: withPath() - returns new instance
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriWithPathReturnsNewInstance(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - withPath() - returns new instance');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/%s?param=value#frag';
        $uri   = new Uri(sprintf($query, 'action'));

        $newInstance = $uri->withPath('/login');
        $I->assertNotEquals($uri, $newInstance);
        $I->assertEquals('/login', $newInstance->getPath());
        $I->assertEquals(sprintf($query, 'login'), (string) $newInstance);
    }

    /**
     * Tests Phalcon\Http\Uri :: withPath() - exception no string
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriWithPathException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withPath() - exception - ' . $example[1]);
        $I->expectThrowable(
            new \InvalidArgumentException(
                'Uri:withPath() requires a string argument instead of ' . $example[0]
            ),
            function () use ($example) {
                $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
                $uri   = new Uri($query);
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
            ['NULL',     'null',     null],
            ['boolean',  'true',     true],
            ['boolean',  'false',    false],
            ['integer',  'number',   1234],
            ['array',    'array',    [ '/action' ]],
            ['stdClass', 'object',   (object) [ '/action' ]],
        ];
    }
}
