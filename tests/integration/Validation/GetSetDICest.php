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

namespace Phalcon\Tests\Integration\Validation;

use IntegrationTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Validation :: getDI() / setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function validationGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getDI() / setDI()');

        $I->skipTest('Need implementation');
    }
}
