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

namespace Phalcon\Test\Integration\Mvc\Url;

use Phalcon\Mvc\Url;
use IntegrationTester;

/**
 * Class GetStaticCest
 */
class GetStaticCest
{
    /**
     * Tests Phalcon\Mvc\Url :: getStatic()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUrlGetStatic(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Url - getStatic()");
        $url = new Url();

        $url->setStaticBaseUri('https://phalconphp.com');

        $expected = 'https://phalconphp.com/en/team';
        $actual   = $url->getStatic('/en/team');
        $I->assertEquals($expected, $actual);
    }
}
