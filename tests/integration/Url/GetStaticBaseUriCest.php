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

class GetStaticBaseUriCest
{
    /**
     * Tests Phalcon\Url :: getStaticBaseUri()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function urlGetStaticBaseUri(IntegrationTester $I)
    {
        $I->wantToTest('Url - getStaticBaseUri()');

        $I->skipTest('Need implementation');
    }
}
