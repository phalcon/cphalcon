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

namespace Phalcon\Test\Integration\Url;

use IntegrationTester;
use Phalcon\Url;

/**
 * Class GetCest
 */
class GetCest
{
    /**
     * Tests Phalcon\Url :: get()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function urlGet(IntegrationTester $I)
    {
        $I->wantToTest("Url - get()");
        $url = new Url();

        $url->setBaseUri('https://phalconphp.com');

        $expected = 'https://phalconphp.com';
        $actual   = $url->get();
        $I->assertEquals($expected, $actual);

        $actual = $url->get('');
        $I->assertEquals($expected, $actual);

        $expected = 'https://phalconphp.com/';
        $actual   = $url->get('/');
        $I->assertEquals($expected, $actual);

        $expected = 'https://phalconphp.com/en/team';
        $actual   = $url->get('/en/team');
        $I->assertEquals($expected, $actual);
    }
}
