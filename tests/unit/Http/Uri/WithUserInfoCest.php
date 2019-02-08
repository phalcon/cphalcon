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
 * Class WithUserInfoCest
 */
class WithUserInfoCest
{
    /**
     * Tests Phalcon\Http\Uri :: withUserInfo() - returns new instance
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriWithUserInfoReturnsNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withUserInfo() - ' . $example[0]);
        $query = 'https://%s@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri(sprintf($query, 'zephir:module'));

        $newInstance = $uri->withUserInfo($example[1], $example[2]);
        $I->assertNotEquals($uri, $newInstance);
        $I->assertEquals($example[3], $newInstance->getUserInfo());
        $I->assertEquals(sprintf($query, $example[3]), (string) $newInstance);
    }

    /**
     * Tests Phalcon\Http\Uri :: withUserInfo() - exception no string
     *
     * @dataProvider getExceptions
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-07
     */
    public function httpUriWithUserInfoException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withUserInfo() - exception - ' . $example[1]);
        $I->expectThrowable(
            new \InvalidArgumentException(
                'Uri:withUserInfo() requires a string argument instead of ' . $example[0]
            ),
            function () use ($example) {
                $query    = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
                $uri      = new Uri($query);
                $instance = $uri->withUserInfo($example[2]);
            }
        );
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            ['valid',     'phalcon',          'secret',           'phalcon:secret'],
            ['user only', 'phalcon',          '',                 'phalcon'],
            ['email',     'phalcon@secret',   'secret@phalcon',   'phalcon%40secret:secret%40phalcon'],
            ['email',     'phalcon:secret',   'secret:phalcon',   'phalcon%3Asecret:secret%3Aphalcon'],
            ['percent',   'phalcon%secret',   'secret%phalcon',   'phalcon%25secret:secret%25phalcon'],
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
