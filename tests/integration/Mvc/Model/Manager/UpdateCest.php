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

class UpdateCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: update()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-06
     */
    public function mvcModelManagerUpdate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - update()');

        $I->skipTest('Need implementation');
    }
}
