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

namespace Phalcon\Test\Integration\Mvc\Collection;

use IntegrationTester;

/**
 * Class SetDirtyStateCest
 */
class SetDirtyStateCest
{
    /**
     * Tests Phalcon\Mvc\Collection :: setDirtyState()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionSetDirtyState(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - setDirtyState()');
        $I->skipTest('Need implementation');
    }
}
