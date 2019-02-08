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
use Phalcon\Http\Message\Uri;
use UnitTester;

/**
 * Class GetAuthorityCest
 */
class GetAuthorityCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: getAuthority()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-07
     */
    public function httpUriGetAuthority(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - getAuthority() - ' . $example[0]);
        $uri = new Uri($example[1]);

        $expected = $example[2];
        $actual   = $uri->getAuthority();
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            ['default', 'https://dev.phalcon.ld', 'dev.phalcon.ld'],
            ['with user info', 'https://phalcon:secret@dev.phalcon.ld', 'phalcon:secret@dev.phalcon.ld'],
            ['with port', 'https://dev.phalcon.ld:8080', 'dev.phalcon.ld:8080'],
            ['full', 'https://phalcon:secret@dev.phalcon.ld:8080', 'phalcon:secret@dev.phalcon.ld:8080'],
        ];
    }
}
