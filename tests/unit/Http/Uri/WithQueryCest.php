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
 * Class WithQueryCest
 */
class WithQueryCest
{
    /**
     * Tests Phalcon\Http\Uri :: withQuery() - returns new instance
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriWithQueryReturnsNewInstance(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - withQuery() - returns new instance');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?%s#frag';
        $uri   = new Uri(sprintf($query, 'param=value'));

        $newInstance = $uri->withQuery('one=two');
        $I->assertNotEquals($uri, $newInstance);
        $I->assertEquals('one=two', $newInstance->getQuery());
        $I->assertEquals(sprintf($query, 'one=two'), (string) $newInstance);
    }

    /**
     * Tests Phalcon\Http\Uri :: withQuery() - exception no string
     *
     * @dataProvider getExamples
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
            new \InvalidArgumentException(
                'Uri:withQuery() requires a string argument instead of ' . $example[0]
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
            ['NULL', 'null', null],
            ['boolean', 'true', true],
            ['boolean', 'false', false],
            ['integer', 'number', 1234],
            ['array', 'array', ['/action']],
            ['stdClass', 'object', (object) ['/action']],
        ];
    }
}
