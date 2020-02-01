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

namespace Phalcon\Test\Integration\Mvc\Model\Query;

use IntegrationTester;

/**
 * Class GetBindParamsCest
 */
class GetBindParamsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query :: getBindParams()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryGetBindParams(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query - getBindParams()');
        $I->skipTest('Need implementation');
    }
}
