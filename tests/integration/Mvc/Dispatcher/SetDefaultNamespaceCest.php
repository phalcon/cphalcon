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

namespace Phalcon\Tests\Integration\Mvc\Dispatcher;

use IntegrationTester;

/**
 * Class SetDefaultNamespaceCest
 */
class SetDefaultNamespaceCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: setDefaultNamespace()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcDispatcherSetDefaultNamespace(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - setDefaultNamespace()');
        $I->skipTest('Need implementation');
    }
}
