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

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use IntegrationTester;

class CreateCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: create()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-06
     */
    public function mvcModelManagerCreate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - create()');

        $I->skipTest('Need implementation');
    }
}
