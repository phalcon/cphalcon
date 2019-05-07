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
 * Class WithSchemeCest
 */
class WithSchemeCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withScheme()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-09
     */
    public function httpMessageUriWithScheme(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - withScheme()');
        $query = '%s://phalcon:secret@dev.phalcon.ld:8000/action?param=value#frag';
        $uri   = new Uri(sprintf($query, 'https'));

        $newInstance = $uri->withScheme('http');
        $I->assertNotEquals($uri, $newInstance);
        $I->assertEquals('http', $newInstance->getScheme());
        $I->assertEquals(sprintf($query, 'http'), (string) $newInstance);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withScheme() - exception no string
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-07
     */
    public function httpUriWithSchemeException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withScheme() - exception - ' . $example[1]);
        $I->expectThrowable(
            new InvalidArgumentException(
                'Method requires a string argument instead of ' . $example[0]
            ),
            function () use ($example) {
                $query    = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
                $uri      = new Uri($query);
                $instance = $uri->withScheme($example[2]);
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
