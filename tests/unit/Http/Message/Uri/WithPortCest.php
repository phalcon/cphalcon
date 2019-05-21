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
use Phalcon\Http\Message\Uri;
use UnitTester;

class WithPortCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: withPort()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-09
     */
    public function httpMessageUriWithPort(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - withPort()');

        $query = 'https://phalcon:secret@dev.phalcon.ld:%s/action?param=value#frag';

        $uri = new Uri(
            sprintf($query, 3306)
        );

        $newInstance = $uri->withPort(11211);

        $I->assertNotEquals($uri, $newInstance);

        $I->assertEquals(
            11211,
            $newInstance->getPort()
        );

        $I->assertEquals(
            sprintf($query, 11211),
            (string) $newInstance
        );
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: withPort() - exception no string
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-07
     */
    public function httpUriWithPortException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Uri - withPort() - ' . $example[0]);

        $query = 'https://phalcon:secret@dev.phalcon.ld%s/action?param=value#frag';

        $uri = new Uri(
            sprintf($query, ':4300')
        );

        $newInstance = $uri->withPort($example[1]);

        $I->assertNotEquals(
            $uri,
            $newInstance
        );

        $I->assertEquals(
            $example[2],
            $newInstance->getPort()
        );

        $I->assertEquals(
            sprintf($query, $example[3]),
            (string) $newInstance
        );
    }

    private function getExamples(): array
    {
        return [
            ['null', null, null, ''],
            ['int', 8080, 8080, ':8080'],
            ['string-int', '8080', 8080, ':8080'],
            ['http', 80, null, ''],
            ['https', 443, null, ''],
        ];
    }
}
