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

namespace Phalcon\Tests\Integration\Mvc\Router\Annotations;

use IntegrationTester;

/**
 * Class AddPurgeCest
 */
class AddPurgeCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: addPurge()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterAnnotationsAddPurge(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - addPurge()');
        $I->skipTest('Need implementation');
    }
}
