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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

/**
 * Class CloneResultMapHydrateCest
 */
class CloneResultMapHydrateCest
{
    /**
     * Tests Phalcon\Mvc\Model :: cloneResultMapHydrate()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCloneResultMapHydrate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - cloneResultMapHydrate()');
        $I->skipTest('Need implementation');
    }
}
