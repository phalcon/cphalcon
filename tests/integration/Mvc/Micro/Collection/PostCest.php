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

namespace Phalcon\Test\Integration\Mvc\Micro\Collection;

use IntegrationTester;

/**
 * Class PostCest
 */
class PostCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: post()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroCollectionPost(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - post()');
        $I->skipTest('Need implementation');
    }
}
