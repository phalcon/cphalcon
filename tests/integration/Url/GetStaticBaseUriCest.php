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

class GetStaticBaseUriCest
{
    /**
     * Tests Phalcon\Url :: getStaticBaseUri()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-16
     */
    public function urlGetStaticBaseUri(IntegrationTester $I)
    {
        $I->wantToTest('Url - getStaticBaseUri()');

        $I->skipTest('Need implementation');
    }
}
