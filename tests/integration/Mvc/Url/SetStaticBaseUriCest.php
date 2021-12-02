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

class SetStaticBaseUriCest
{
    /**
     * Tests Phalcon\Mvc\Url :: setStaticBaseUri()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function mvcUrlSetStaticBaseUri(IntegrationTester $I)
    {
        $I->wantToTest('Url - setStaticBaseUri()');

        $I->skipTest('Need implementation');
    }
}
