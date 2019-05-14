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
 * Class GetHandlersCest
 */
class GetHandlersCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: getHandlers()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroCollectionGetHandlers(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - getHandlers()');
        $I->skipTest('Need implementation');
    }
}
