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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset;

use IntegrationTester;

/**
 * Class SerializeCest
 */
class SerializeCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset :: serialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSerialize(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset - serialize()');
        $I->skipTest('Need implementation');
    }
}
