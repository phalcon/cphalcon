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

namespace Phalcon\Tests\Integration\Mvc\Model\Query\Status;

use IntegrationTester;

/**
 * Class GetModelCest
 */
class GetModelCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Status :: getModel()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryStatusGetModel(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Status - getModel()');
        $I->skipTest('Need implementation');
    }
}
