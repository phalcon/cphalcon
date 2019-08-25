<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Collection\Manager;

use IntegrationTester;

/**
 * Class InitializeCest
 */
class InitializeCest
{
    /**
     * Tests Phalcon\Mvc\Collection\Manager :: initialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcCollectionManagerInitialize(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection\Manager - initialize()');
        $I->skipTest('Need implementation');
    }
}
