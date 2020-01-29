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

namespace Phalcon\Test\Integration\Url;

use IntegrationTester;

class SetStaticBaseUriCest
{
    /**
     * Tests Phalcon\Url :: setStaticBaseUri()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function urlSetStaticBaseUri(IntegrationTester $I)
    {
        $I->wantToTest('Url - setStaticBaseUri()');

        $I->skipTest('Need implementation');
    }
}
