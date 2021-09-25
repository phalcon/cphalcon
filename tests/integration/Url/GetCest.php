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

namespace Phalcon\Tests\Integration\Url;

use IntegrationTester;
use Phalcon\Url;

class GetCest
{
    /**
     * Tests Phalcon\Url :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function urlGet(IntegrationTester $I)
    {
        $I->wantToTest('Url - get()');

        $url = new Url();

        $url->setBaseUri('https://phalcon.io');

        $I->assertEquals(
            'https://phalcon.io',
            $url->get()
        );

        $I->assertEquals(
            'https://phalcon.io',
            $url->get('')
        );

        $I->assertEquals(
            'https://phalcon.io/',
            $url->get('/')
        );

        $I->assertEquals(
            'https://phalcon.io/en/team',
            $url->get('/en/team')
        );
    }
}
