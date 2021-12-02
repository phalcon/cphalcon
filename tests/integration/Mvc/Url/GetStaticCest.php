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

namespace Phalcon\Tests\Integration\Mvc\Url;

use IntegrationTester;
use Phalcon\Mvc\Url;

class GetStaticCest
{
    /**
     * Tests Phalcon\Mvc\Url :: getStatic()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcUrlGetStatic(IntegrationTester $I)
    {
        $I->wantToTest('Url - getStatic()');
        $url = new Url();

        $url->setStaticBaseUri('https://phalcon.io');

        $expected = 'https://phalcon.io/en/team';
        $actual   = $url->getStatic('/en/team');
        $I->assertEquals($expected, $actual);
    }
}
